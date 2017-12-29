$NetBSD: patch-file.c,v 1.1 2017/12/29 17:55:13 maya Exp $

Avoid buffer overflow from magical side effecting macro expansion

--- file.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ file.c
@@ -156,7 +156,9 @@ loadfile(const char *path)
 	if (len == 0)
 		return(NULL);
 
-	XMALLOC(lfile, ++len * sizeof(char *));
+	++len;
+
+	XMALLOC(lfile, len * sizeof(char *));
 
 	for (i = 0; i < len; i++)
 		lfile[i] = NULL;
