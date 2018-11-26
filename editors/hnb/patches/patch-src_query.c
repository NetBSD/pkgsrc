$NetBSD: patch-src_query.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/query.c.orig	2003-03-14 02:29:13.000000000 +0000
+++ src/query.c
@@ -27,7 +27,7 @@
 
 static char query[100];
 
-static int getquery_cmd (int argc, char **argv, void *data)
+static uint64_t getquery_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -36,7 +36,7 @@ static int getquery_cmd (int argc, char 
 		ui_getstr (argv[1], &query[0]);
 	else
 		ui_getstr ("enter string", &query[0]);
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
