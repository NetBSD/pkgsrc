$NetBSD: patch-frmts_gif_biggifdataset.cpp,v 1.1 2014/05/23 13:04:10 obache Exp $

* giflib>=5.1 API change

--- frmts/gif/biggifdataset.cpp.orig	2012-10-09 00:58:25.000000000 +0000
+++ frmts/gif/biggifdataset.cpp
@@ -337,7 +337,12 @@ CPLErr BIGGIFDataset::ReOpen()
 /*      If the file is already open, close it so we can restart.        */
 /* -------------------------------------------------------------------- */
     if( hGifFile != NULL )
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        DGifCloseFile( hGifFile, NULL );
+#else
         DGifCloseFile( hGifFile );
+#endif
 
 /* -------------------------------------------------------------------- */
 /*      If we are actually reopening, then we assume that access to     */
@@ -411,7 +416,12 @@ CPLErr BIGGIFDataset::ReOpen()
 
     if( RecordType != IMAGE_DESC_RECORD_TYPE )
     {
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        DGifCloseFile( hGifFile, NULL );
+#else
         DGifCloseFile( hGifFile );
+#endif
         hGifFile = NULL;
 
         CPLError( CE_Failure, CPLE_OpenFailed, 
@@ -421,7 +431,12 @@ CPLErr BIGGIFDataset::ReOpen()
     
     if (DGifGetImageDesc(hGifFile) == GIF_ERROR)
     {
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        DGifCloseFile( hGifFile, NULL );
+#else
         DGifCloseFile( hGifFile );
+#endif
         hGifFile = NULL;
 
         CPLError( CE_Failure, CPLE_OpenFailed, 
