$NetBSD: patch-sound__oss.c,v 1.2 2018/08/05 21:27:04 adam Exp $

Do not hard-code sound device.

--- sound_oss.c.orig	2018-04-21 17:02:14.000000000 +0000
+++ sound_oss.c
@@ -36,11 +36,7 @@
 
 #define DEBUG 0
 
-#if defined (__NetBSD__) || defined (__OpenBSD__)
-static const char * const dspname = "/dev/audio";
-#else
-static const char * const dspname = "/dev/dsp";
-#endif
+static const char * const dspname = DEVOSSAUDIO;
 
 static int dsp_fd;
 
