$NetBSD: patch-xfer1.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- xfer1.c.orig	2013-03-01 14:10:33.000000000 +0000
+++ xfer1.c
@@ -56,6 +56,8 @@
 #include "xfer.h"
 #include "str.h"
 
+static void release_xfer_subforest(struct forest_node *node);
+
 struct xfer_ctrl_block xc;
 
 char *merge_paths();
@@ -361,7 +363,7 @@ char **full_path;
 /*
  * print_xfer_forest
  */
-print_xfer_forest()
+static void print_xfer_forest(void)
 {
 	struct forest_node *node[MAXLEVELS];
 	int level = 0;
@@ -411,8 +413,7 @@ release_xfer_forest()
 /*
  * release_xfer_subforest - Release memory used by forest starting at "node".
  */
-release_xfer_subforest(node)
-struct forest_node *node;
+static void release_xfer_subforest(struct forest_node *node)
 {
 	struct forest_node *ptr1;
 	struct forest_node *ptr2;
