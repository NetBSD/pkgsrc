$NetBSD: patch-frmts_gif_gifabstractdataset.cpp,v 1.1 2014/05/23 13:04:10 obache Exp $

* giflib>=5.1 API change

--- frmts/gif/gifabstractdataset.cpp.orig	2012-10-09 00:58:25.000000000 +0000
+++ frmts/gif/gifabstractdataset.cpp
@@ -82,7 +82,12 @@ GIFAbstractDataset::~GIFAbstractDataset(
     }
 
     if( hGifFile )
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && \
+	(GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5)
+        DGifCloseFile( hGifFile, NULL );
+#else
         DGifCloseFile( hGifFile );
+#endif
 
     if( fp != NULL )
         VSIFCloseL( fp );
