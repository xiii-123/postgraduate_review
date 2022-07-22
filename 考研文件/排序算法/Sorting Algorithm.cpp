#include<stdio.h>
#include<stdlib.h>
//求数组的长度 
#define len(nums) (sizeof(nums)/sizeof(nums[0]))
//归并排序的辅助数组 
int *Assist = (int*)malloc(50*sizeof(int));
//交换两数 
void swap(int &x, int &y) {
    int temp = y;
    y = x;
    x = temp;
}

//遍历数组 
void show(int nums[], int n){
	printf("len of nums:%d	",n);
	for (int i = 0; i < n; i++){
		printf("%d,",nums[i]);
	}
	printf("\n");
}

//快速排序——划分 
int Partition(int nums[], int low, int high){
	int pivot = nums[low];
	while(low < high){
		while(nums[high] >= pivot && low < high)	high--;
		nums[low] = nums[high];
		while(nums[low] <= pivot && low < high)		low++;
		nums[high] = nums[low];
	}
	nums[low] = pivot;
	return low;
}

//堆排序——调整堆 
void HeapAdjust(int nums[], int k, int len){
	nums[0] = nums[k];
	for (int i = k*2; i <= len; i *= 2){
		if (i < len && nums[i] > nums[i+1])
			i++;
		if (nums[0] <= nums[i])	break;
		else{
			nums[k] = nums[i];
			k = i;
		}
	}
	nums[k] = nums[0];
}

//堆排序——建立大根堆 
void BuildMaxHeap(int nums[], int len){
	for (int i = len/2; i > 0; i--){
		HeapAdjust(nums,i,len);
	}
		
}

//归并排序——归并 
void Merge(int nums[], int low, int mid, int high){
	int i,j,k;
	for (k = low; k <= high; k++){
		Assist[k] = nums[k];
	}
	for (i = low, j = mid+1, k = i; i <= mid && j <= high; k++){
		if (Assist[i] <= Assist[j])
			nums[k] = Assist[i++];
		else
			nums[k] = Assist[j++];
	}
	while(j <= high) nums[k++] = Assist[j++];
	while(i <= mid) nums[k++] = Assist[i++]; 
}

//插入排序 
void InsertSort(int nums[], int n){
	int temp,j;
	for (int i = 1; i < n; i++){
		if (nums[i] < nums[i-1]){
			temp = nums[i];
			for (j = i-1; j >=0 && nums[j] > temp; j--)
				nums[j+1] = nums[j];
			nums[j+1] = temp;
		}
	}
}
 
void ShellSort(int nums[], int n){
	int d,i,temp,j;
	for (d = n/2; d >= 1; d = d/2){
		for (i = d; i < n; i++){
			if (nums[i] < nums[i-d]){
				temp = nums[i];
				for (j = i-d; j >= 0 && nums[j] > temp; j = j-d)
					nums[j+d] = nums[j];
				nums[j+d] = temp;
			}
		}
	}
}

//交换排序 
void BubbleSort(int nums[], int n){
	int flag;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}

void QuickSort(int nums[], int low, int high){
	if (low < high){
		int pi = Partition(nums, low, high);
		QuickSort(nums, low, pi-1);
		QuickSort(nums, pi+1, high);
	}
}

//选择排序
void ChooseSort(int nums[], int n){
	int min;
	for (int i = 0; i < n-1; i++){
		min = i;
		for (int j = i; j < n; j++){
			if (nums[j] < nums[min])
				min = j;
		}
		if (min != i)
			swap(nums[i],nums[min]);
	}
} 

void HeapSort(int nums[], int len){
	int temp;
	BuildMaxHeap(nums,len);
	for (int i = len; i > 1; i--){
		swap(nums[i], nums[1]);
		HeapAdjust(nums,1,i-1);
	}
} 

//归并排序 
void MergeSort(int nums[], int low, int high){
	if (low < high){
		int mid = (low+high)/2;
		MergeSort(nums,low,mid);
		MergeSort(nums,mid+1,high);
		Merge(nums,low,mid,high);
	}
}

int main(){
	int nums[] = {503,87,512,61,908,170,897,257,653,462};
	show(nums,len(nums));
	ChooseSort(nums,len(nums));
	show(nums,len(nums));
}
