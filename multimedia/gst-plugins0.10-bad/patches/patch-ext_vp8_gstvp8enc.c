$NetBSD: patch-ext_vp8_gstvp8enc.c,v 1.1 2015/12/25 20:07:42 joerg Exp $

--- ext/vp8/gstvp8enc.c.orig	2015-12-25 18:16:43.000000000 +0000
+++ ext/vp8/gstvp8enc.c
@@ -843,7 +843,7 @@ gst_vp8_enc_set_format (GstBaseVideoEnco
 
   /* prepare cached image buffer setup */
   image = &encoder->image;
-  memset (image, 0, sizeof (image));
+  memset (image, 0, sizeof (*image));
 
   image->fmt = VPX_IMG_FMT_I420;
   image->bps = 12;
