$NetBSD: patch-util_gif2mask.c,v 1.2 2014/05/16 10:00:33 obache Exp $

* Fix build with giflib 5.0.4.
* Catch error with gifib 5.0 manner.

--- util/gif2mask.c.orig	2013-06-08 14:08:51.000000000 +0000
+++ util/gif2mask.c
@@ -13,10 +13,18 @@
 
 #define max(a,b,c) (((a)>(b))?(((c)>(a))?(c):(a)):(((c)>(b))?(c):(b)))
 
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
 
@@ -27,12 +35,22 @@ unsigned char *readGif(char *fileName, i
   unsigned char colorMap[256];
   unsigned char *data;
   int i, nColors, size;
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
 
