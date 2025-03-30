$NetBSD: patch-Alc_backends_alsa.c,v 1.1 2025/03/30 09:32:07 nia Exp $

Support building on non-Linux.

--- Alc/backends/alsa.c.orig	2025-03-24 15:38:32.096309021 +0000
+++ Alc/backends/alsa.c
@@ -35,6 +35,9 @@
 
 #include <alsa/asoundlib.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
 
 static const ALCchar alsaDevice[] = "ALSA Default";
 
