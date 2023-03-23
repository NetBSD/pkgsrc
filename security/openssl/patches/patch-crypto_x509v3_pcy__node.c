$NetBSD: patch-crypto_x509v3_pcy__node.c,v 1.1 2023/03/23 06:16:22 wiz Exp $

x509: excessive resource use verifying policy constraints
https://github.com/openssl/openssl/commit/879f7080d7e141f415c79eaa3a8ac4a3dad0348b

--- crypto/x509v3/pcy_node.c.orig	2023-02-07 13:37:05.000000000 +0000
+++ crypto/x509v3/pcy_node.c
@@ -59,10 +59,15 @@ X509_POLICY_NODE *level_find_node(const 
 X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *level,
                                  X509_POLICY_DATA *data,
                                  X509_POLICY_NODE *parent,
-                                 X509_POLICY_TREE *tree)
+                                 X509_POLICY_TREE *tree,
+                                 int extra_data)
 {
     X509_POLICY_NODE *node;
 
+    /* Verify that the tree isn't too large.  This mitigates CVE-2023-0464 */
+    if (tree->node_maximum > 0 && tree->node_count >= tree->node_maximum)
+        return NULL;
+
     node = OPENSSL_zalloc(sizeof(*node));
     if (node == NULL) {
         X509V3err(X509V3_F_LEVEL_ADD_NODE, ERR_R_MALLOC_FAILURE);
@@ -70,7 +75,7 @@ X509_POLICY_NODE *level_add_node(X509_PO
     }
     node->data = data;
     node->parent = parent;
-    if (level) {
+    if (level != NULL) {
         if (OBJ_obj2nid(data->valid_policy) == NID_any_policy) {
             if (level->anyPolicy)
                 goto node_error;
@@ -90,7 +95,7 @@ X509_POLICY_NODE *level_add_node(X509_PO
         }
     }
 
-    if (tree) {
+    if (extra_data) {
         if (tree->extra_data == NULL)
             tree->extra_data = sk_X509_POLICY_DATA_new_null();
         if (tree->extra_data == NULL){
@@ -103,6 +108,7 @@ X509_POLICY_NODE *level_add_node(X509_PO
         }
     }
 
+    tree->node_count++;
     if (parent)
         parent->nchild++;
 
