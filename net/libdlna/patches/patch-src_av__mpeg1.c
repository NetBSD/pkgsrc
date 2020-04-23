$NetBSD: patch-src_av__mpeg1.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/av_mpeg1.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/av_mpeg1.c
@@ -42,7 +42,7 @@ probe_mpeg1 (AVFormatContext *ctx dlna_u
     return NULL;
   
   /* check for MPEG-1 video codec */
-  if (codecs->vc->codec_id != CODEC_ID_MPEG1VIDEO)
+  if (codecs->vc->codec_id != AV_CODEC_ID_MPEG1VIDEO)
     return NULL;
 
   /* video bitrate must be CBR at 1,151,929.1 bps */
@@ -72,7 +72,7 @@ probe_mpeg1 (AVFormatContext *ctx dlna_u
     return NULL;
 
   /* check for MPEG-1 Layer-2 audio codec */
-  if (codecs->ac->codec_id != CODEC_ID_MP2)
+  if (codecs->ac->codec_id != AV_CODEC_ID_MP2)
     return NULL;
   
   /* supported channels: stereo only */
