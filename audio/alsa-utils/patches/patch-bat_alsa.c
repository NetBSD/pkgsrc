$NetBSD: patch-bat_alsa.c,v 1.2 2023/11/23 16:15:04 ryoon Exp $

--- bat/alsa.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ bat/alsa.c
@@ -31,6 +31,10 @@
 #include "latencytest.h"
 #include "os_compat.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE EPIPE
+#endif
+
 struct pcm_container {
 	snd_pcm_t *handle;
 	snd_pcm_uframes_t period_size;
