$NetBSD: patch-sound__oss.c,v 1.1 2017/12/14 22:12:19 adam Exp $

Do not hard-code sound device.

--- sound_oss.c.orig	2013-12-15 23:17:45.000000000 +0000
+++ sound_oss.c
@@ -36,7 +36,7 @@
 
 #define DEBUG 0
 
-static const char * const dspname = "/dev/dsp";
+static const char * const dspname = DEVOSSAUDIO;
 
 static int dsp_fd;
 
