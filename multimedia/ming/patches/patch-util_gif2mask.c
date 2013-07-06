$NetBSD: patch-util_gif2mask.c,v 1.1 2013/07/06 07:43:13 ryoon Exp $

* Fix build with giflib 5.0.4.
* Catch error with gifib 5.0 manner.

--- util/gif2mask.c.orig	2013-06-08 14:08:51.000000000 +0000
+++ util/gif2mask.c
@@ -13,10 +13,12 @@
 
 #define max(a,b,c) (((a)>(b))?(((c)>(a))?(c):(a)):(((c)>(b))?(c):(b)))
 
+int ErrorCode;
+
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
+  PrintGifError(ErrorCode);
   exit(-1);
 }
 
@@ -28,7 +30,7 @@ unsigned char *readGif(char *fileName, i
   unsigned char *data;
   int i, nColors, size;
 
-  if((file = DGifOpenFileName(fileName)) == NULL)
+  if((file = DGifOpenFileName(fileName, &ErrorCode)) == NULL)
     error("Error opening file");
 
   if(DGifSlurp(file) != GIF_OK)
