$NetBSD: patch-crypto_x509v3_pcy__local.h,v 1.1 2023/03/23 06:16:22 wiz Exp $

x509: excessive resource use verifying policy constraints
https://github.com/openssl/openssl/commit/879f7080d7e141f415c79eaa3a8ac4a3dad0348b

--- crypto/x509v3/pcy_local.h.orig	2023-02-07 13:37:05.000000000 +0000
+++ crypto/x509v3/pcy_local.h
@@ -111,6 +111,11 @@ struct X509_POLICY_LEVEL_st {
 };
 
 struct X509_POLICY_TREE_st {
+    /* The number of nodes in the tree */
+    size_t node_count;
+    /* The maximum number of nodes in the tree */
+    size_t node_maximum;
+
     /* This is the tree 'level' data */
     X509_POLICY_LEVEL *levels;
     int nlevel;
@@ -159,7 +164,8 @@ X509_POLICY_NODE *tree_find_sk(STACK_OF(
 X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *level,
                                  X509_POLICY_DATA *data,
                                  X509_POLICY_NODE *parent,
-                                 X509_POLICY_TREE *tree);
+                                 X509_POLICY_TREE *tree,
+                                 int extra_data);
 void policy_node_free(X509_POLICY_NODE *node);
 int policy_node_match(const X509_POLICY_LEVEL *lvl,
                       const X509_POLICY_NODE *node, const ASN1_OBJECT *oid);
