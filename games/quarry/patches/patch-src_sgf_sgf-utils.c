$NetBSD: patch-src_sgf_sgf-utils.c,v 1.1 2012/11/16 00:50:40 joerg Exp $

--- src/sgf/sgf-utils.c.orig	2012-11-15 15:22:55.000000000 +0000
+++ src/sgf/sgf-utils.c
@@ -63,7 +63,7 @@ static int	strings_are_equal (const void
 				   const void *second_string);
 
 
-inline void
+void
 sgf_utils_play_node_move (const SgfNode *node, Board *board)
 {
   assert (node);
@@ -1717,7 +1717,7 @@ do_enter_tree (SgfGameTree *tree, SgfNod
 }
 
 
-inline void
+void
 sgf_utils_do_switch_to_given_node (SgfGameTree *tree, SgfNode *node)
 {
   SgfNode *path_scan;
