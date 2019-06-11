$NetBSD: patch-alsa.c,v 1.1 2019/06/11 11:54:56 nia Exp $

Build on NetBSD.

--- alsa.c.orig	2016-11-16 00:54:37.000000000 +0000
+++ alsa.c
@@ -36,6 +36,10 @@
 #include "options.h"
 #include "log.h"
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 #define BUFFER_MAX_USEC	300000
 
 static snd_pcm_t *handle = NULL;
