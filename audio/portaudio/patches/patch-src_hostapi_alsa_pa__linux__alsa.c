$NetBSD: patch-src_hostapi_alsa_pa__linux__alsa.c,v 1.1 2019/10/20 11:10:49 nia Exp $

Support building on non-Linux systems.

--- src/hostapi/alsa/pa_linux_alsa.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/hostapi/alsa/pa_linux_alsa.c
@@ -79,6 +79,10 @@
 
 #include "pa_linux_alsa.h"
 
+#ifndef ESTRPIPE
+    #define ESTRPIPE EPIPE
+#endif
+
 /* Add missing define (for compatibility with older ALSA versions) */
 #ifndef SND_PCM_TSTAMP_ENABLE
     #define SND_PCM_TSTAMP_ENABLE SND_PCM_TSTAMP_MMAP
