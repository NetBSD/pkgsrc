$NetBSD: patch-src_audio__g726.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_g726.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_g726.c
@@ -31,7 +31,7 @@ audio_profile_guess_g726 (AVCodecContext
   if (!ac)
     return AUDIO_PROFILE_INVALID;
 
-  if (ac->codec_id != CODEC_ID_ADPCM_G726)
+  if (ac->codec_id != AV_CODEC_ID_ADPCM_G726)
     return AUDIO_PROFILE_INVALID;
   
   if (ac->channels != 1)
