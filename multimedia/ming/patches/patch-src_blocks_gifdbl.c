$NetBSD: patch-src_blocks_gifdbl.c,v 1.1 2013/07/06 07:43:13 ryoon Exp $

* Fix build with giflib 5.0.

--- src/blocks/gifdbl.c.orig	2010-10-10 07:19:23.000000000 +0000
+++ src/blocks/gifdbl.c
@@ -227,7 +227,7 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
-	if((file = DGifOpenFileName(fileName)) == NULL)
+	if((file = DGifOpenFileName(fileName, NULL)) == NULL)
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
@@ -246,7 +246,7 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
-	if((file = DGifOpen(input, (InputFunc) gifReadFunc)) == NULL)
+	if((file = DGifOpen(input, (InputFunc) gifReadFunc, NULL)) == NULL)
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
