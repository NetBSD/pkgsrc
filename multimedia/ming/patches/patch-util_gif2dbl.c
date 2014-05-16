$NetBSD: patch-util_gif2dbl.c,v 1.2 2014/05/16 09:43:30 wiz Exp $

* Fix build with giflib 5.0.4.
* Catch error with gifib 5.0 manner.

--- util/gif2dbl.c.orig	2013-06-08 14:08:51.000000000 +0000
+++ util/gif2dbl.c
@@ -19,10 +19,12 @@
 
 #include "libming.h"
 
+int ErrorCode;
+
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
+  PrintGifError(ErrorCode);
   exit(-1);
 }
 
@@ -59,7 +61,7 @@ unsigned char *readGif(char *fileName, i
   unsigned char *p;
   int i, nColors, size, alpha, bgColor, alignedWidth;
 
-  if((file = DGifOpenFileName(fileName)) == NULL)
+  if((file = DGifOpenFileName(fileName, &ErrorCode)) == NULL)
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
@@ -190,7 +192,7 @@ unsigned char *readGif(char *fileName, i
   }
 
 	/* Done! */
-  DGifCloseFile(file);
+  DGifCloseFile(file, NULL);
 
   *length = size;
   return data;
