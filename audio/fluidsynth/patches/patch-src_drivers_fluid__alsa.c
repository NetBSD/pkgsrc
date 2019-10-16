$NetBSD: patch-src_drivers_fluid__alsa.c,v 1.1 2019/10/16 19:25:44 nia Exp $

Support building on non-Linux.

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
