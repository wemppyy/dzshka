#include <iostream>
#include <ctime>

using namespace std;



template <typename T>
T* init_arr(int size) {
	T* arr = new T[size];
	return arr;
}

template <typename T>
T* create_arr(int size) {
	T* arr = init_arr<T>(size);
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
	return arr;
}

template <typename T>
void print_arr(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

template <typename T>
void delete_arr(T* &arr) {
	delete[] arr;
	arr = nullptr;
}

template <typename T>
void push_back(T* &arr, int &size, int value) {
	T* new_arr = init_arr<T>(size + 1);
	for (int i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[size] = value;
	delete[] arr;
	arr = new_arr;
	size++;
}

template <typename T>
void insert(T*& arr, int& size, int index, int value) {
	T* new_arr = init_arr<T>(size + 1);
	for (int i = 0; i < index; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[index] = value;
	for (int i = index; i < size; i++) {
		new_arr[i + 1] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	size++;
}

template <typename T>
void delete_by_index(T*& arr, int& size, int index) {
	T* new_arr = init_arr<T>(size - 1);
	for (int i = 0; i < index; i++) {
		new_arr[i] = arr[i];
	}
	for (int i = index; i < size; i++) {
		new_arr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = new_arr;
	size--;
}

int main() {
	srand(time(0));

	int size = 0;


	while (true) {
		int operation = 0;
		system("cls");
		cout << "Menu:\n"
			"1. Specify the size of the array [Required]\n"
			"2. Create array with random numbers [Required]\n"
			"3. Print your array\n"
			"4. Add an element to the end of an array\n"
			"5. Add an element to an array by index\n"
			"6. Delete an element to an array by index\n"
			"7. Delete array\n" << endl;
		cin >> operation;
		system("cls");
		switch (operation) {
			
			case 1:

				cout << "Enter size of the array: ";
				cin >> size;
				cout << endl;
				break;
			case 2:
				if (size != 0) {
					create_arr(size);
				cout << "Array created" << endl;
				}
				else {
					cout << "Enter the size!" << endl;
					break;
				}
				break;
			default:
				cout << "Choose the correct operation!" << endl;
				break;
		}
		system("pause");
	}

	/*
	int size = 5;
	int * arr = create_arr<int>(size);
	print_arr(arr, size);
	cout << endl;
	push_back(arr, size, 4);
	print_arr(arr, size);
	cout << endl;
	insert(arr, size, 4, 100);
	print_arr(arr, size);
	cout << endl;
	delete_by_index(arr, size, 3);
	print_arr(arr, size);
	delete_arr(arr);
	*/

	return 0;
}