$NetBSD: patch-src_sgf_sgf-tree.c,v 1.1 2012/11/16 00:50:40 joerg Exp $

--- src/sgf/sgf-tree.c.orig	2012-11-15 15:21:23.000000000 +0000
+++ src/sgf/sgf-tree.c
@@ -1271,7 +1271,7 @@ sgf_node_count_subtree_nodes (const SgfN
 /* Dynamically allocate an SgfProperty structure and initialize its
  * type and pointer to the next property with given values.
  */
-inline SgfProperty *
+SgfProperty *
 sgf_property_new (SgfGameTree *tree, SgfType type, SgfProperty *next)
 {
   SgfProperty *property = memory_pool_alloc (&tree->property_pool);
@@ -1288,7 +1288,7 @@ sgf_property_new (SgfGameTree *tree, Sgf
  * types need to be freed.  Values of other types are stored in the
  * property structure itself.
  */
-inline void
+void
 sgf_property_delete (SgfProperty *property, SgfGameTree *tree)
 {
   assert (property);
