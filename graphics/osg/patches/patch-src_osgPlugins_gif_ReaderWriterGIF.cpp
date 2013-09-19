$NetBSD: patch-src_osgPlugins_gif_ReaderWriterGIF.cpp,v 1.1 2013/09/19 08:07:05 obache Exp $

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
