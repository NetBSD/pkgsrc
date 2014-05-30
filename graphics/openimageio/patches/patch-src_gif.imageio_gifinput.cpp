$NetBSD: patch-src_gif.imageio_gifinput.cpp,v 1.1 2014/05/30 11:33:32 joerg Exp $

--- src/gif.imageio/gifinput.cpp.orig	2014-05-28 13:28:44.000000000 +0000
+++ src/gif.imageio/gifinput.cpp
@@ -497,7 +497,7 @@ inline bool
 GIFInput::close (void)
 {
     if (m_gif_file) {
-        if (DGifCloseFile (m_gif_file) == GIF_ERROR) {
+        if (DGifCloseFile (m_gif_file, NULL) == GIF_ERROR) {
             error ("Error trying to close the file.");
             return false;
         }
