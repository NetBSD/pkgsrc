$NetBSD: patch-src_sound__oss.c,v 1.1 2019/05/05 10:12:59 adam Exp $

Do not hard-code sound device.

--- src/sound_oss.c.orig	2018-04-21 17:02:14.000000000 +0000
+++ src/sound_oss.c
@@ -38,11 +38,7 @@
 
 #define DEBUG 0
 
-#if defined (__NetBSD__) || defined (__OpenBSD__)
-static const char * const dspname = "/dev/audio";
-#else
-static const char * const dspname = "/dev/dsp";
-#endif
+static const char * const dspname = DEVOSSAUDIO;
 
 static int dsp_fd;
 
