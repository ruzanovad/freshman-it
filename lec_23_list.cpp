// ���� �� ������ ������������ ������
#include <iostream>

struct Node
{
	double data;
	Node* next;
};

class StackList
{
	private:
		Node* top_ptr;
		int error; //0 ��� � �������,1 - �������� ������, 2 - �������� �� �������

	public:
		StackList();
		StackList(const StackList&);
		~StackList();

		double top(); // ���������� �������
		void pop(); // ������� �������
		void push(double); //��������
		bool empty();

		void makeEmpty();
		friend void print(const StackList&);
};

StackList::StackList()
{
	top_ptr = nullptr;
	error = 0;
	std::cout << "��� ����������� �� ���������\n";
}

bool StackList::empty()
{
	return top_ptr == nullptr;
}

double StackList::top()
{
	if (empty())
	{
		error = 2;
		return 1;
	}
	error = 0;
	return top_ptr->data;
	// (*top_ptr).data
}

void StackList::push(double x)
{
	Node* tmp = nullptr;
	tmp = new (std::nothrow) Node;
	if (tmp == nullptr)
		error = 1;
	else
	{
		error = 0;
		tmp->data = x;
		tmp->next = top_ptr;
		top_ptr = tmp;
		std::cout << "push\n";
	}

}

void print(const StackList &st)
{
	Node* iter = st.top_ptr;
	if (iter != nullptr)
	{
		std::cout << iter->data << " ";
		while (iter->next != nullptr)
		{
			iter = iter->next;
			std::cout << iter->data << " ";
		}
		std::cout << "\n";
	}
	
}

void StackList::pop()
{
	if (!empty())
	{
		Node* tmp = top_ptr;
		top_ptr = top_ptr->next;
		delete tmp;
		error = 0;
		std::cout << "pop\n";
	}
	else
		error = 2;

}

StackList::~StackList()
{
	//Node* tmp = top_ptr;
	//while (tmp->next != nullptr)
	//{
	//	delete 
	//}
}

int main()
{
	setlocale(LC_ALL, "rus");
	StackList st1;
	st1.push(1); st1.push(2.384343);
	print(st1);
}