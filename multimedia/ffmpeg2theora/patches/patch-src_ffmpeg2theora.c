$NetBSD: patch-src_ffmpeg2theora.c,v 1.1 2013/10/22 12:45:29 tron Exp $

Fix build with "ffmpeg2" package.

--- src/ffmpeg2theora.c.orig	2012-01-29 08:00:19.000000000 +0000
+++ src/ffmpeg2theora.c	2013-10-22 13:05:45.000000000 +0100
@@ -132,6 +132,9 @@
   return ret;
 }
 
+/* Deprecated by the "ffmpeg" maintainers. */
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 19200
+
 /**
  * Allocate and initialise an AVFrame.
  */
