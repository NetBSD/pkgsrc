$NetBSD: patch-src_heif.imageio_heifoutput.cpp,v 1.1 2025/07/08 05:54:48 wiz Exp $

Fix build with libheif 1.20.

--- src/heif.imageio/heifoutput.cpp.orig	2025-07-08 05:50:55.597638959 +0000
+++ src/heif.imageio/heifoutput.cpp
@@ -149,7 +149,7 @@ HeifOutput::write_scanline(int y, int /*
                            stride_t xstride)
 {
     data           = to_native_scanline(format, data, xstride, scratch);
-    int hystride   = 0;
+    size_t hystride   = 0;
     uint8_t* hdata = m_himage.get_plane(heif_channel_interleaved, &hystride);
     hdata += hystride * (y - m_spec.y);
     memcpy(hdata, data, hystride);
