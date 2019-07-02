$NetBSD: patch-op_alsa.c,v 1.1 2019/07/02 06:23:50 nia Exp $

Support NetBSD.

--- op/alsa.c.orig	2019-01-29 09:09:08.000000000 +0000
+++ op/alsa.c
@@ -59,6 +59,10 @@
 
 #include <alsa/asoundlib.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 static sample_format_t alsa_sf;
 static snd_pcm_t *alsa_handle;
 static snd_pcm_format_t alsa_fmt;
