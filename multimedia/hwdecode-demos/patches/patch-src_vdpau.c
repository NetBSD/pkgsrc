$NetBSD: patch-src_vdpau.c,v 1.1 2020/08/17 12:22:50 tnn Exp $

Compile error.

--- src/vdpau.c.orig	2014-06-18 12:46:39.000000000 +0000
+++ src/vdpau.c
@@ -852,7 +852,7 @@ int vdpau_decode(void)
     status = vdpau_decoder_render(
         vdpau->decoder,
         vdpau->video_surface.vdp_surface,
-        (VdpPictureInfo)&vdpau->picture_info,
+        (const VdpPictureInfo*)&vdpau->picture_info,
         vdpau->bitstream_buffers_count,
         vdpau->bitstream_buffers
     );
