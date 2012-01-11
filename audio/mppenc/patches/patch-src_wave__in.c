$NetBSD: patch-src_wave__in.c,v 1.1 2012/01/11 19:51:26 hans Exp $

--- src/wave_in.c.orig  2006-11-03 22:48:56.000000000 +0100
+++ src/wave_in.c       2012-01-02 12:03:16.188471300 +0100
@@ -19,6 +19,11 @@
 
 #include "mppenc.h"
 
+#ifdef __sun
+#define SOUND_PCM_WRITE_CHANNELS	SNDCTL_DSP_CHANNELS
+#define SOUND_PCM_WRITE_BITS		SNDCTL_DSP_SETFMT
+#define SOUND_PCM_WRITE_RATE		SNDCTL_DSP_SPEED
+#endif
 
 static int
 init_in ( const int  SampleCount,

