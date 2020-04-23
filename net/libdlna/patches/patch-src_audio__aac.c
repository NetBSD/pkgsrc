$NetBSD: patch-src_audio__aac.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_aac.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_aac.c
@@ -311,7 +311,7 @@ audio_profile_guess_aac_priv (AVCodecCon
     return AUDIO_PROFILE_INVALID;
 
   /* check for AAC variants codec */
-  if (ac->codec_id != CODEC_ID_AAC)
+  if (ac->codec_id != AV_CODEC_ID_AAC)
     return AUDIO_PROFILE_INVALID;
   
   switch (type)
