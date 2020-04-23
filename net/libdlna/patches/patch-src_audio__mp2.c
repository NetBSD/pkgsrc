$NetBSD: patch-src_audio__mp2.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_mp2.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_mp2.c
@@ -31,7 +31,7 @@ audio_profile_guess_mp2 (AVCodecContext 
   if (!ac)
     return AUDIO_PROFILE_INVALID;
 
-  if (ac->codec_id != CODEC_ID_MP2)
+  if (ac->codec_id != AV_CODEC_ID_MP2)
     return AUDIO_PROFILE_INVALID;
   
   if (ac->channels > 5)
