$NetBSD: patch-alsa.c,v 1.1 2024/03/16 17:53:11 nia Exp $

Allow building the alsa plugin on NetBSD (for test purposes).

--- alsa.c.orig	2015-06-29 09:56:08.000000000 +0000
+++ alsa.c
@@ -59,6 +59,10 @@
 
 #include <alsa/asoundlib.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 static sample_format_t alsa_sf;
 static snd_pcm_t *alsa_handle;
 static snd_pcm_format_t alsa_fmt;
