#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            this->data = value;
            this->next = NULL;
        };
};

class SinglyLinkedList{
    public:
        vector<int> arr;
        Node *node, *head;
        SinglyLinkedList(vector<int> arr){
            this->head = arr.size() > 0 ? new Node(arr[0]) : NULL;
            Node *currentNode = this->head;
            for(int i = 1; i < arr.size(); i++){
                currentNode->next = new Node(arr[i]);
                currentNode = currentNode->next;
            };
        };

        Node *at(int index){
            Node *iterator = this->head;
            for(int i = 0; i < index; i++){
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }

        int findNode(int key) {
            Node *iterator = this->head;
            int count = 0;
            while (iterator != NULL) {
                if (iterator-> data == key) return count;
                iterator = iterator->next;
                count++;
            }
            return 0;
        }
        void printList(){
            Node *iterator = this->head;
            string str = "";
            while(iterator != NULL){
                str += to_string(iterator->data) + " ";
                iterator = iterator->next;
            }
            cout << str << endl;
        }

};

int main(){
    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});
    cout << numList->at(2)->data << endl;
    cout << numList->at(3)->data << endl;
    cout << numList->at(4)->data << endl;

    numList->printList();
    Node *thirdEle = numList->at(2);
    Node *tempNode = thirdEle->next;
    Node *newNode = new Node(40);
    thirdEle->next = newNode;
    newNode->next = tempNode;

    cout << numList->at(2)->data << endl;
    cout << numList->at(3)->data << endl;
    cout << numList->at(4)->data << endl;
    numList->printList();

}
