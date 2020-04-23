$NetBSD: patch-src_audio__wma.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_wma.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_wma.c
@@ -55,7 +55,7 @@ audio_profile_guess_wma (AVCodecContext 
     return ap;
 
   /* check for WMA codec */
-  if (ac->codec_id != CODEC_ID_WMAV1 && ac->codec_id != CODEC_ID_WMAV2)
+  if (ac->codec_id != AV_CODEC_ID_WMAV1 && ac->codec_id != AV_CODEC_ID_WMAV2)
     return ap;
 
   if (ac->sample_rate <= 48000)
