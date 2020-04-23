$NetBSD: patch-src_av__wmv9.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/av_wmv9.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/av_wmv9.c
@@ -245,7 +245,7 @@ probe_wmv9 (AVFormatContext *ctx dlna_un
     return NULL;
 
   /* check for WMV3 (Simple and Main profiles) video codec */
-  if (codecs->vc->codec_id != CODEC_ID_WMV3)
+  if (codecs->vc->codec_id != AV_CODEC_ID_WMV3)
     return NULL;
 
   /* get video profile */
