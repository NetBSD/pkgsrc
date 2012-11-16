$NetBSD: patch-src_sgf_sgf.h,v 1.1 2012/11/16 00:50:40 joerg Exp $

--- src/sgf/sgf.h.orig	2012-11-15 15:20:43.000000000 +0000
+++ src/sgf/sgf.h
@@ -640,10 +640,9 @@ SgfNode *	 sgf_node_traverse_backward (c
 int		 sgf_node_count_subtree_nodes (const SgfNode *node);
 
 
-inline SgfProperty *
-		 sgf_property_new (SgfGameTree *tree, SgfType type,
+SgfProperty *	 sgf_property_new (SgfGameTree *tree, SgfType type,
 				   SgfProperty *next);
-inline void	 sgf_property_delete (SgfProperty *property,
+void	 sgf_property_delete (SgfProperty *property,
 				      SgfGameTree *tree);
 void		 sgf_property_delete_at_link (SgfProperty **link,
 					      SgfGameTree *tree);
@@ -813,7 +812,7 @@ typedef enum {
 } SgfPasteResult;
 
 
-inline void   sgf_utils_play_node_move (const SgfNode *node, Board *board);
+void   sgf_utils_play_node_move (const SgfNode *node, Board *board);
 void	      sgf_utils_format_node_move (const SgfGameTree *tree,
 					  const SgfNode *node,
 					  StringBuffer *buffer,
