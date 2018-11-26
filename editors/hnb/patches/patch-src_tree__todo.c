$NetBSD: patch-src_tree__todo.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/tree_todo.c.orig	2003-03-09 17:23:18.000000000 +0000
+++ src/tree_todo.c
@@ -260,7 +260,7 @@ int calc_percentage_size (Node *node, in
 
 #include "cli.h"
 
-static int toggle_todo_cmd (int argc, char **argv, void *data)
+static uint64_t toggle_todo_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -271,15 +271,15 @@ static int toggle_todo_cmd (int argc, ch
 		node_unset(pos,"type");
 	}
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int toggle_done_cmd (int argc, char **argv, void *data)
+static uint64_t toggle_done_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
 	if (strcmp(fixnullstring(node_get(pos,"type")),"todo")) {	/* bail out if not todo info set */
-		return (int) pos;
+		return PTR_TO_UINT64(pos);
 	}
 
 	if (!strcmp(fixnullstring(node_get(pos,"done")),"yes")) {	/* bail out if not todo info set */
@@ -288,7 +288,7 @@ static int toggle_done_cmd (int argc, ch
 		node_set(pos,"done","yes");
 	}
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
