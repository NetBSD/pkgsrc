$NetBSD: patch-src_image__png.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/image_png.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/image_png.c
@@ -76,7 +76,7 @@ probe_png (AVFormatContext *ctx,
     return NULL;
   
   /* check for PNG compliant codec */
-  if (codecs->vc->codec_id != CODEC_ID_PNG)
+  if (codecs->vc->codec_id != AV_CODEC_ID_PNG)
     return NULL;
 
   for (i = 0; png_profiles_mapping[i].profile; i++)
