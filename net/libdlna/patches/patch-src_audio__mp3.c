$NetBSD: patch-src_audio__mp3.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_mp3.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_mp3.c
@@ -47,7 +47,7 @@ audio_is_valid_mp3_common (AVCodecContex
     return 0;
 
   /* check for MP3 codec */
-  if (ac->codec_id != CODEC_ID_MP3)
+  if (ac->codec_id != AV_CODEC_ID_MP3)
     return 0;
   
   /* only mono and stereo are supported */
