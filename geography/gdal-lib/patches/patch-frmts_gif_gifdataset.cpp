$NetBSD: patch-frmts_gif_gifdataset.cpp,v 1.1 2014/05/23 13:04:10 obache Exp $

* giflib>=5.1 API change

--- frmts/gif/gifdataset.cpp.orig	2012-10-09 00:58:25.000000000 +0000
+++ frmts/gif/gifdataset.cpp
@@ -385,13 +385,23 @@ GDALDataset *GIFDataset::Open( GDALOpenI
             CPLDebug( "GIF",
                       "Due to limitations of the GDAL GIF driver we deliberately avoid\n"
                       "opening large GIF files (larger than 100 megapixels).");
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+            DGifCloseFile( hGifFile, NULL );
+#else
             DGifCloseFile( hGifFile );
+#endif
             VSIFCloseL( fp );
             return NULL;
         }
     }
 
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+    DGifCloseFile( hGifFile, NULL );
+#else
     DGifCloseFile( hGifFile );
+#endif
 
     VSIFSeekL( fp, 0, SEEK_SET);
 
@@ -416,7 +426,12 @@ GDALDataset *GIFDataset::Open( GDALOpenI
     if( nGifErr != GIF_OK || hGifFile->SavedImages == NULL )
     {
         VSIFCloseL( fp );
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        DGifCloseFile(hGifFile, NULL);
+#else
         DGifCloseFile(hGifFile);
+#endif
 
         if( nGifErr == D_GIF_ERR_DATA_TOO_BIG )
         {
@@ -648,7 +663,12 @@ GIFDataset::CreateCopy( const char * psz
     {
         GifFreeMapObject(psGifCT);
         GDALPrintGifError(hGifFile, "Error writing gif file.");
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        EGifCloseFile(hGifFile, NULL);
+#else
         EGifCloseFile(hGifFile);
+#endif
         VSIFCloseL( fp );
         return NULL;
     }
@@ -672,7 +692,12 @@ GIFDataset::CreateCopy( const char * psz
     if (EGifPutImageDesc(hGifFile, 0, 0, nXSize, nYSize, bInterlace, NULL) == GIF_ERROR )
     {
         GDALPrintGifError(hGifFile, "Error writing gif file.");
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        EGifCloseFile(hGifFile, NULL);
+#else
         EGifCloseFile(hGifFile);
+#endif
         VSIFCloseL( fp );
         return NULL;
     }
@@ -755,7 +780,12 @@ GIFDataset::CreateCopy( const char * psz
 /* -------------------------------------------------------------------- */
 /*      cleanup                                                         */
 /* -------------------------------------------------------------------- */
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+    if (EGifCloseFile(hGifFile, NULL) == GIF_ERROR)
+#else
     if (EGifCloseFile(hGifFile) == GIF_ERROR)
+#endif
     {
         CPLError( CE_Failure, CPLE_AppDefined, 
                   "EGifCloseFile() failed.\n" );
@@ -806,7 +836,12 @@ GIFDataset::CreateCopy( const char * psz
 
 error:
     if (hGifFile)
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        EGifCloseFile(hGifFile, NULL);
+#else
         EGifCloseFile(hGifFile);
+#endif
     if (fp)
         VSIFCloseL( fp );
     if (pabyScanline)
