$NetBSD: patch-binary.c,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Use nbcompat headers.
Update zlib API.

--- binary.c.orig	2005-04-22 21:02:42.000000000 +0000
+++ binary.c
@@ -29,3 +29,8 @@
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
@@ -69,3 +74,3 @@ bin_file(FILE *f)
 int
-gzbin_file(gzFile *f)
+gzbin_file(gzFile f)
 {
