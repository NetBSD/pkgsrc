$NetBSD: patch-src_heif.imageio_heifinput.cpp,v 1.1 2025/07/08 05:54:48 wiz Exp $

Fix build with libheif 1.20.

--- src/heif.imageio/heifinput.cpp.orig	2025-07-08 05:50:37.935201903 +0000
+++ src/heif.imageio/heifinput.cpp
@@ -394,7 +394,7 @@ HeifInput::read_native_scanline(int subi
     if (y < 0 || y >= m_spec.height)  // out of range scanline
         return false;
 
-    int ystride          = 0;
+    size_t ystride          = 0;
     const uint8_t* hdata = m_himage.get_plane(heif_channel_interleaved,
                                               &ystride);
     if (!hdata) {
