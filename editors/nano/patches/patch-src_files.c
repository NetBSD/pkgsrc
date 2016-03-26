$NetBSD: patch-src_files.c,v 1.1 2016/03/26 20:21:37 bsiegert Exp $

--- src/files.c.orig	2016-02-25 20:47:10.000000000 +0000
+++ src/files.c
@@ -43,7 +43,7 @@ bool has_valid_path(const char *filename
     if (strrchr(filename, '/') == NULL)
 	parentdir = mallocstrcpy(NULL, ".");
     else
-	parentdir = dirname(mallocstrcpy(NULL, filename));
+	parentdir = mallocstrcpy(NULL, dirname(filename));
 
     if (stat(parentdir, &parentinfo) == -1) {
 	if (errno == ENOENT)
