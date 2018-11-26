$NetBSD: patch-src_state.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/state.c.orig	2003-03-09 17:28:07.000000000 +0000
+++ src/state.c
@@ -29,7 +29,7 @@
 
 static Node *savedtree = NULL;
 
-static int save_state_cmd (int argc, char **argv, void *data)
+static uint64_t save_state_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 	Node *i;
@@ -58,10 +58,10 @@ static int save_state_cmd (int argc, cha
 			savedtree = node_recurse (savedtree);
 	}
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int restore_state_cmd (int argc, char **argv, void *data)
+static uint64_t restore_state_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -74,7 +74,7 @@ static int restore_state_cmd (int argc, 
 		tree_free (savedtree);
 		savedtree = NULL;
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
