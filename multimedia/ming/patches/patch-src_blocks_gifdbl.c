$NetBSD: patch-src_blocks_gifdbl.c,v 1.3 2014/05/16 10:00:33 obache Exp $

* Fix build with giflib>=5.0.

--- src/blocks/gifdbl.c.orig	2010-10-10 07:19:23.000000000 +0000
+++ src/blocks/gifdbl.c
@@ -203,7 +203,13 @@ readGif(GifFileType *file, dblData resul
 	}
 
 	/* Done! */
-	DGifCloseFile(file);
+#if (GIFLIB_MAJOR + 0) >= 5 && (GIFLIB_MINOR + 0 >= 1) || (GIFLIB_MAJOR + 0 ) > 5
+	DGifCloseFile(file, NULL);
+#else
+	if (DGifCloseFile(file) != GIF_OK) {
+		free(file);
+	}
+#endif
 
 	result->data = malloc(outsize = (int)floor(size*1.01+12));
 
@@ -227,7 +233,11 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
+#if (GIFLIB_MAJOR + 0) >= 5
+	if((file = DGifOpenFileName(fileName, NULL)) == NULL)
+#else
 	if((file = DGifOpenFileName(fileName)) == NULL)
+#endif
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
@@ -246,7 +256,11 @@ SWFDBLBitmapData newSWFDBLBitmapData_fro
 	SWFDBLBitmapData ret;
 	struct dbl_data gifdata;
 
+#if (GIFLIB_MAJOR + 0) >= 5
+	if((file = DGifOpen(input, (InputFunc) gifReadFunc, NULL)) == NULL)
+#else
 	if((file = DGifOpen(input, (InputFunc) gifReadFunc)) == NULL)
+#endif
 		return NULL;
 	if(!readGif(file, &gifdata))
 		return NULL;
