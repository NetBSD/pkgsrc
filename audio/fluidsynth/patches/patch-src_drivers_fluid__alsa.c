$NetBSD: patch-src_drivers_fluid__alsa.c,v 1.2 2024/10/30 14:33:16 wiz Exp $

Support building on non-Linux.
https://github.com/FluidSynth/fluidsynth/pull/1414

--- src/drivers/fluid_alsa.c.orig	2019-09-27 14:53:27.000000000 +0000
+++ src/drivers/fluid_alsa.c
@@ -43,6 +43,14 @@
 
 #define BUFFER_LENGTH 512
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
+#ifndef EBADFD
+#define EBADFD EBADF
+#endif
+
 /** fluid_alsa_audio_driver_t
  *
  * This structure should not be accessed directly. Use audio port
