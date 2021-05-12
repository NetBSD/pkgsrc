$NetBSD: patch-bat_alsa.c,v 1.1 2021/05/12 14:13:22 ryoon Exp $

--- bat/alsa.c.orig	2020-10-15 11:32:33.000000000 +0000
+++ bat/alsa.c
@@ -29,6 +29,10 @@
 #include "alsa.h"
 #include "latencytest.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE EPIPE
+#endif
+
 struct pcm_container {
 	snd_pcm_t *handle;
 	snd_pcm_uframes_t period_size;
