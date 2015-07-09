$NetBSD: patch-file.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.
Update zlib API.

--- file.c.orig	2007-12-06 20:33:48.000000000 +0000
+++ file.c
@@ -29,3 +29,10 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#include <nbcompat/stdio.h>
+#else
 #include <sys/cdefs.h>
+#include <stdio.h>
+#endif
 #ifndef lint
@@ -38,3 +45,2 @@ __RCSID("$NetBSD: file.c,v 1.3 2007/12/0
 #include <err.h>
-#include <stdio.h>
 #include <stdlib.h>
@@ -55,3 +61,3 @@ struct file {
 	mmf_t *mmf;
-	gzFile *gzf;
+	gzFile gzf;
 };
@@ -88,3 +94,3 @@ grepfgetln(FILE *f, size_t *len)
 static char *
-gzfgetln(gzFile *f, size_t *len)
+gzfgetln(gzFile f, size_t *len)
 {
