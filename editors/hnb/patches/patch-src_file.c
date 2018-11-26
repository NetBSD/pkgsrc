$NetBSD: patch-src_file.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/file.c.orig	2003-03-13 22:55:13.000000000 +0000
+++ src/file.c
@@ -150,7 +150,7 @@
 }
 
 
-static int cmd_save (int argc,char **argv, void *data)
+static uint64_t cmd_save (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -167,10 +167,10 @@
 			docmd (node_root (pos), buf);
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
-static int cmd_revert (int argc,char **argv, void *data)
+static uint64_t cmd_revert (int argc,char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -185,7 +185,7 @@
 			pos=docmd (pos, buf);
 		}
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 
