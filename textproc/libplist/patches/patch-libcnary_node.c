$NetBSD: patch-libcnary_node.c,v 1.1 2012/04/22 16:11:13 wiz Exp $

Non-void functions need return values.

--- libcnary/node.c.orig	2012-01-11 14:29:30.000000000 +0000
+++ libcnary/node.c
@@ -104,7 +104,7 @@ int node_detach(node_t* parent, node_t* 
 
 int node_insert(node_t* parent, unsigned int index, node_t* child)
 {
-	if (!parent || !child) return;
+	if (!parent || !child) return -1;
 	child->isLeaf = TRUE;
 	child->isRoot = FALSE;
 	child->parent = parent;
