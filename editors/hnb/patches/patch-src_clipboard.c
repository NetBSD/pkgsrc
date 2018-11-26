$NetBSD: patch-src_clipboard.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/clipboard.c.orig	2003-03-09 17:42:20.000000000 +0000
+++ src/clipboard.c
@@ -29,7 +29,7 @@
 
 static Node *clipboard = NULL;
 
-static int copy_cmd (int argc,char **argv, void *data)
+static uint64_t copy_cmd (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -39,10 +39,10 @@ static int copy_cmd (int argc,char **arg
 	clipboard = node_new ();
 
 	clipboard = tree_duplicate (pos, clipboard);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int cut_cmd (int argc,char **argv, void *data)
+static uint64_t cut_cmd (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -53,10 +53,10 @@ static int cut_cmd (int argc,char **argv
 
 	clipboard = tree_duplicate (pos, clipboard);
 	pos = node_remove (pos);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int paste_cmd (int argc,char **argv, void *data)
+static uint64_t paste_cmd (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -68,7 +68,7 @@ static int paste_cmd (int argc,char **ar
 		temp = node_insert_down (pos);
 		tree_duplicate (clipboard, temp);
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
