$NetBSD: patch-libs_util_quakeio.c,v 1.1 2017/02/18 14:01:22 joerg Exp $

--- libs/util/quakeio.c.orig	2017-02-18 02:03:20.448822400 +0000
+++ libs/util/quakeio.c
@@ -72,7 +72,7 @@ static __attribute__ ((unused)) const ch
 struct QFile_s {
 	FILE *file;
 #ifdef HAVE_ZLIB
-	gzFile *gzfile;
+	gzFile gzfile;
 #endif
 	off_t size;
 	off_t start;
