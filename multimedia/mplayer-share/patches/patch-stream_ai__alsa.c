$NetBSD: patch-stream_ai__alsa.c,v 1.1 2019/06/04 13:39:38 nia Exp $

Make this build on NetBSD.

--- stream/ai_alsa.c.orig	2011-11-14 09:58:24.000000000 +0000
+++ stream/ai_alsa.c
@@ -19,7 +19,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/time.h>
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
+#endif
 #define ALSA_PCM_NEW_HW_PARAMS_API
 #define ALSA_PCM_NEW_SW_PARAMS_API
 #include <alsa/asoundlib.h>
