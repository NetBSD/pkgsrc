$NetBSD: patch-src_av__mpeg4__part10.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/av_mpeg4_part10.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/av_mpeg4_part10.c
@@ -1221,7 +1221,7 @@ probe_avc (AVFormatContext *ctx,
     return NULL;
 
   /* check for H.264/AVC codec */
-  if (codecs->vc->codec_id != CODEC_ID_H264)
+  if (codecs->vc->codec_id != AV_CODEC_ID_H264)
     return NULL;
 
   /* check for a supported container */
