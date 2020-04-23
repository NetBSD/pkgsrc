$NetBSD: patch-src_image__jpeg.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/image_jpeg.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/image_jpeg.c
@@ -92,10 +92,10 @@ probe_jpeg (AVFormatContext *ctx,
     return NULL;
 
   /* check for JPEG compliant codec */
-  if (codecs->vc->codec_id != CODEC_ID_MJPEG &&
-      codecs->vc->codec_id != CODEC_ID_MJPEGB &&
-      codecs->vc->codec_id != CODEC_ID_LJPEG &&
-      codecs->vc->codec_id != CODEC_ID_JPEGLS)
+  if (codecs->vc->codec_id != AV_CODEC_ID_MJPEG &&
+      codecs->vc->codec_id != AV_CODEC_ID_MJPEGB &&
+      codecs->vc->codec_id != AV_CODEC_ID_LJPEG &&
+      codecs->vc->codec_id != AV_CODEC_ID_JPEGLS)
     return NULL;
 
   for (i = 0; jpeg_profiles_mapping[i].profile; i++)
