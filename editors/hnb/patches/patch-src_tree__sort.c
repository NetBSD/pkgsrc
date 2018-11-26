$NetBSD: patch-src_tree__sort.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/tree_sort.c.orig	2003-03-14 00:12:44.000000000 +0000
+++ src/tree_sort.c
@@ -141,7 +141,7 @@ static int cmp_descending(Node *a,Node *
 	return cmp_todo(b,a);
 }
 
-static int sort_cmd (int argc, char **argv, void *data)
+static uint64_t sort_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	int (*cmp) (Node *a, Node *b)=cmp_todo;
@@ -155,7 +155,7 @@ static int sort_cmd (int argc, char **ar
 	node_mergesort (node_top (pos), nodes_down (node_top (pos)) + 1, cmp);
 	if (node_left (pos))
 		node_left (pos)->right = node_top (pos);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
