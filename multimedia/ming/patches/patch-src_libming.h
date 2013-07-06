$NetBSD: patch-src_libming.h,v 1.1 2013/07/06 07:43:13 ryoon Exp $

* Introduce custom PrintGifError() from util/qprintf.c of giflib 5.0.4.

--- src/libming.h.orig	2013-06-08 14:08:51.000000000 +0000
+++ src/libming.h
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <math.h>
+#include <gif_lib.h>
 
 
 #include "ming.h"
@@ -78,9 +79,14 @@ typedef unsigned char BOOL;
 
 #if GIFLIB_GIFERRORSTRING
 static void
-PrintGifError(void)
+PrintGifError(int ErrorCode)
 {
-	fprintf(stderr, "\nGIF-LIB error: %s.\n", GifErrorString());
+	char *Err = GifErrorString(ErrorCode);
+
+	if (Err != NULL)
+		fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+	else
+		fprintf(stderr, "\nGIF-LIB undefined error %d.\n", ErrorCode);
 }
 #endif
 
