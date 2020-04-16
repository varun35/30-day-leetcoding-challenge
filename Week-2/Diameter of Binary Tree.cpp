/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==0) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==0) return 0;
        
        int rheight=height(root->right);
        int lheight=height(root->left);
        
        int ldiam=diameterOfBinaryTree(root->left);
        int rdiam=diameterOfBinaryTree(root->right);
        
        return max(lheight+rheight,max(ldiam,rdiam));
    }
};
