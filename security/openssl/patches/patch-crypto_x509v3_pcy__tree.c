$NetBSD: patch-crypto_x509v3_pcy__tree.c,v 1.1 2023/03/23 06:16:22 wiz Exp $

x509: excessive resource use verifying policy constraints
https://github.com/openssl/openssl/commit/879f7080d7e141f415c79eaa3a8ac4a3dad0348b

--- crypto/x509v3/pcy_tree.c.orig	2023-02-07 13:37:05.000000000 +0000
+++ crypto/x509v3/pcy_tree.c
@@ -14,6 +14,18 @@
 #include "pcy_local.h"
 
 /*
+ * If the maximum number of nodes in the policy tree isn't defined, set it to
+ * a generous default of 1000 nodes.
+ *
+ * Defining this to be zero means unlimited policy tree growth which opens the
+ * door on CVE-2023-0464.
+ */
+
+#ifndef OPENSSL_POLICY_TREE_NODES_MAX
+# define OPENSSL_POLICY_TREE_NODES_MAX 1000
+#endif
+
+/*
  * Enable this to print out the complete policy tree at various point during
  * evaluation.
  */
@@ -168,6 +180,9 @@ static int tree_init(X509_POLICY_TREE **
         return X509_PCY_TREE_INTERNAL;
     }
 
+    /* Limit the growth of the tree to mitigate CVE-2023-0464 */
+    tree->node_maximum = OPENSSL_POLICY_TREE_NODES_MAX;
+
     /*
      * http://tools.ietf.org/html/rfc5280#section-6.1.2, figure 3.
      *
@@ -184,7 +199,7 @@ static int tree_init(X509_POLICY_TREE **
     level = tree->levels;
     if ((data = policy_data_new(NULL, OBJ_nid2obj(NID_any_policy), 0)) == NULL)
         goto bad_tree;
-    if (level_add_node(level, data, NULL, tree) == NULL) {
+    if (level_add_node(level, data, NULL, tree, 1) == NULL) {
         policy_data_free(data);
         goto bad_tree;
     }
@@ -243,7 +258,8 @@ static int tree_init(X509_POLICY_TREE **
  * Return value: 1 on success, 0 otherwise
  */
 static int tree_link_matching_nodes(X509_POLICY_LEVEL *curr,
-                                    X509_POLICY_DATA *data)
+                                    X509_POLICY_DATA *data,
+                                    X509_POLICY_TREE *tree)
 {
     X509_POLICY_LEVEL *last = curr - 1;
     int i, matched = 0;
@@ -253,13 +269,13 @@ static int tree_link_matching_nodes(X509
         X509_POLICY_NODE *node = sk_X509_POLICY_NODE_value(last->nodes, i);
 
         if (policy_node_match(last, node, data->valid_policy)) {
-            if (level_add_node(curr, data, node, NULL) == NULL)
+            if (level_add_node(curr, data, node, tree, 0) == NULL)
                 return 0;
             matched = 1;
         }
     }
     if (!matched && last->anyPolicy) {
-        if (level_add_node(curr, data, last->anyPolicy, NULL) == NULL)
+        if (level_add_node(curr, data, last->anyPolicy, tree, 0) == NULL)
             return 0;
     }
     return 1;
@@ -272,7 +288,8 @@ static int tree_link_matching_nodes(X509
  * Return value: 1 on success, 0 otherwise.
  */
 static int tree_link_nodes(X509_POLICY_LEVEL *curr,
-                           const X509_POLICY_CACHE *cache)
+                           const X509_POLICY_CACHE *cache,
+                           X509_POLICY_TREE *tree)
 {
     int i;
 
@@ -280,7 +297,7 @@ static int tree_link_nodes(X509_POLICY_L
         X509_POLICY_DATA *data = sk_X509_POLICY_DATA_value(cache->data, i);
 
         /* Look for matching nodes in previous level */
-        if (!tree_link_matching_nodes(curr, data))
+        if (!tree_link_matching_nodes(curr, data, tree))
             return 0;
     }
     return 1;
@@ -311,7 +328,7 @@ static int tree_add_unmatched(X509_POLIC
     /* Curr may not have anyPolicy */
     data->qualifier_set = cache->anyPolicy->qualifier_set;
     data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
-    if (level_add_node(curr, data, node, tree) == NULL) {
+    if (level_add_node(curr, data, node, tree, 1) == NULL) {
         policy_data_free(data);
         return 0;
     }
@@ -373,7 +390,7 @@ static int tree_link_any(X509_POLICY_LEV
     }
     /* Finally add link to anyPolicy */
     if (last->anyPolicy &&
-        level_add_node(curr, cache->anyPolicy, last->anyPolicy, NULL) == NULL)
+        level_add_node(curr, cache->anyPolicy, last->anyPolicy, tree, 0) == NULL)
         return 0;
     return 1;
 }
@@ -555,7 +572,7 @@ static int tree_calculate_user_set(X509_
             extra->qualifier_set = anyPolicy->data->qualifier_set;
             extra->flags = POLICY_DATA_FLAG_SHARED_QUALIFIERS
                 | POLICY_DATA_FLAG_EXTRA_NODE;
-            node = level_add_node(NULL, extra, anyPolicy->parent, tree);
+            node = level_add_node(NULL, extra, anyPolicy->parent, tree, 1);
         }
         if (!tree->user_policies) {
             tree->user_policies = sk_X509_POLICY_NODE_new_null();
@@ -582,7 +599,7 @@ static int tree_evaluate(X509_POLICY_TRE
 
     for (i = 1; i < tree->nlevel; i++, curr++) {
         cache = policy_cache_set(curr->cert);
-        if (!tree_link_nodes(curr, cache))
+        if (!tree_link_nodes(curr, cache, tree))
             return X509_PCY_TREE_INTERNAL;
 
         if (!(curr->flags & X509_V_FLAG_INHIBIT_ANY)
