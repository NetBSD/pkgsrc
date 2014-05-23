$NetBSD: patch-src_osgPlugins_gif_ReaderWriterGIF.cpp,v 1.2 2014/05/23 13:45:07 obache Exp $

* GIFLIB 5.x API change 

--- src/osgPlugins/gif/ReaderWriterGIF.cpp.orig	2011-05-05 12:39:35.000000000 +0000
+++ src/osgPlugins/gif/ReaderWriterGIF.cpp
@@ -370,7 +370,11 @@ GifImageStream** obj)
     int interlacedoffset[] = { 0, 4, 2, 1 };
     int interlacedjumps[] = { 8, 8, 4, 2 };
 
+#if GIFLIB_MAJOR >= 5
+    giffile = DGifOpen(&fin,gif_read_stream, NULL);
+#else
     giffile = DGifOpen(&fin,gif_read_stream);
+#endif
     if (!giffile)
     {
         giferror = ERR_OPEN;
@@ -557,7 +561,11 @@ GifImageStream** obj)
     *width_ret = giffile->SWidth;
     *height_ret = giffile->SHeight;
     *numComponents_ret = 4;
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(giffile, NULL);
+#else
     DGifCloseFile(giffile);
+#endif
     return buffer;
 }
 
