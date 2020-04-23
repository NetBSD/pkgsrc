$NetBSD: patch-src_audio__atrac3.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_atrac3.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_atrac3.c
@@ -39,7 +39,7 @@ audio_profile_guess_atrac (AVCodecContex
     return AUDIO_PROFILE_INVALID;
 
 #if LIBAVCODEC_VERSION_INT >= ((51<<16)+(40<<8)+4)
-  if (ac->codec_id == CODEC_ID_ATRAC3)
+  if (ac->codec_id == AV_CODEC_ID_ATRAC3)
     return AUDIO_PROFILE_ATRAC;
 #endif
 
