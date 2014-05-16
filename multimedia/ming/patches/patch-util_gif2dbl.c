$NetBSD: patch-util_gif2dbl.c,v 1.3 2014/05/16 10:00:33 obache Exp $

* Fix build with giflib 5.0.4.
* Catch error with gifib 5.0 manner.

--- util/gif2dbl.c.orig	2013-06-08 14:08:51.000000000 +0000
+++ util/gif2dbl.c
@@ -19,10 +19,18 @@
 
 #include "libming.h"
 
+#if (GIFLIB_MAJOR + 0) >= 5
+void error(char *msg, int ErrorCode)
+#else
 void error(char *msg)
+#endif
 {
   printf("%s:\n\n", msg);
+#if (GIFLIB_MAJOR + 0) >= 5
+  PrintGifError(ErrorCode);
+#else
   PrintGifError();
+#endif
   exit(-1);
 }
 
@@ -58,12 +66,22 @@ unsigned char *readGif(char *fileName, i
   unsigned char *data;
   unsigned char *p;
   int i, nColors, size, alpha, bgColor, alignedWidth;
+#if (GIFLIB_MAJOR + 0) >= 5
+  int ErrorCode;
 
+  if((file = DGifOpenFileName(fileName, &ErrorCode)) == NULL)
+    error("Error opening file", ErrorCode);
+#else
   if((file = DGifOpenFileName(fileName)) == NULL)
     error("Error opening file");
+#endif
 
   if(DGifSlurp(file) != GIF_OK)
+#if (GIFLIB_MAJOR + 0) >= 5
+    error("Error slurping file", file->Error);
+#else
     error("Error slurping file");
+#endif
 
   /* data should now be available */
 
@@ -190,7 +208,13 @@ unsigned char *readGif(char *fileName, i
   }
 
 	/* Done! */
-  DGifCloseFile(file);
+#if (GIFLIB_MAJOR + 0) >= 5 && (GIFLIB_MINOR >= 1) || (GIFLIB_MAJOR + 0) > 5
+  DGifCloseFile(file, NULL);
+#else
+  if (DGifCloseFile(file) != GIF_OK) {
+    free(file);
+  }
+#endif
 
   *length = size;
   return data;
