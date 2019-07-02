#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
// #include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void levelOrderR(Node* root, vector<vector<int>>& v, int level) {
        if (!root) return;
        if (level == v.size())
            v.push_back(vector<int>{root->val});
        else
            v[level].push_back(root->val);
        for (const auto& n : root->children) {
            levelOrderR(n, v, level + 1);
        }

    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if (!root) return v;
        levelOrderR(root, v, 0);
        return v;
    }

    vector<vector<int>> levelOrderQ(Node* root) {
        vector<vector<int>> v;
        if (!root) return v;
        queue<const Node*> q;
        q.push(root);
        unsigned long nodesAtLevel = 1;
        do {
            vector<int> lvl;
            while (nodesAtLevel) {
                const Node* f = q.front();
                q.pop();
                --nodesAtLevel;
                lvl.push_back(f->val);
                for (const auto& ch : f->children)
                    q.push(ch);
            }
            v.push_back(lvl);
            nodesAtLevel = q.size();
        } while (nodesAtLevel);
        return v;
    }
};

void test1() {
    vector<Node*> e;
    Node *n5 = new Node(5, e);
    Node *n6 = new Node(6, e);
    Node *n2 = new Node(2, e);
    Node *n4 = new Node(4, e);
    Node *n3 = new Node(3, vector<Node*>{n5, n6});
    Node *n1 = new Node(1, vector<Node*>{n3, n2, n4});

    cout << " [1], [3,2,4], [5,6]? " << Solution().levelOrder(n1) << endl;
//    cout << " ? " << Solution().func() << endl;
//    cout << " ? " << Solution().func() << endl;
}

void test2() {

}

void test3() {

}