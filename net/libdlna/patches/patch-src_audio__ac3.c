$NetBSD: patch-src_audio__ac3.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_ac3.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_ac3.c
@@ -39,7 +39,7 @@ audio_profile_guess_ac3 (AVCodecContext 
     return AUDIO_PROFILE_INVALID;
 
   /* check for AC3 codec */
-  if (ac->codec_id != CODEC_ID_AC3)
+  if (ac->codec_id != AV_CODEC_ID_AC3)
     return AUDIO_PROFILE_INVALID;
   
   /* supported channels: 1/0, 2/0, 3/0, 2/1, 3/1, 2/2, 3/2 */
