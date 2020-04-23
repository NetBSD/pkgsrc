$NetBSD: patch-src_audio__lpcm.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_lpcm.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_lpcm.c
@@ -45,8 +45,8 @@ audio_profile_guess_lpcm (AVCodecContext
     return AUDIO_PROFILE_INVALID;
 
   /* check for 16-bit signed network-endian PCM codec  */
-  if (ac->codec_id != CODEC_ID_PCM_S16BE &&
-      ac->codec_id != CODEC_ID_PCM_S16LE)
+  if (ac->codec_id != AV_CODEC_ID_PCM_S16BE &&
+      ac->codec_id != AV_CODEC_ID_PCM_S16LE)
     return AUDIO_PROFILE_INVALID;
 
   /* supported channels: mono or stereo */
