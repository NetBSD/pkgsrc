$NetBSD: patch-src_libming.h,v 1.3 2014/05/16 10:00:33 obache Exp $

* Introduce custom PrintGifError() from util/qprintf.c of giflib>=5.

--- src/libming.h.orig	2013-06-08 14:08:51.000000000 +0000
+++ src/libming.h
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <math.h>
+#include <gif_lib.h>
 
 
 #include "ming.h"
@@ -78,9 +79,26 @@ typedef unsigned char BOOL;
 
 #if GIFLIB_GIFERRORSTRING
 static void
+#if (GIFLIB_MAJOR + 0) >= 5
+PrintGifError(int ErrorCode)
+#else
 PrintGifError(void)
+#endif
 {
+#if (GIFLIB_MAJOR + 0) >= 5
+#  if GIFLIB_MAJOR == 5 && GIFLIB_MINOR == 0
+	char *Err = GifErrorString(ErrorCode);
+#  else
+	const char *Err = GifErrorString(ErrorCode);
+#  endif
+
+	if (Err != NULL)
+		fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+	else
+		fprintf(stderr, "\nGIF-LIB undefined error %d.\n", ErrorCode);
+#else
 	fprintf(stderr, "\nGIF-LIB error: %s.\n", GifErrorString());
+#endif
 }
 #endif
 
