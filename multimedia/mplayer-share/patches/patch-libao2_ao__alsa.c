$NetBSD: patch-libao2_ao__alsa.c,v 1.1 2019/06/04 13:39:38 nia Exp $

Make this build on NetBSD.

--- libao2/ao_alsa.c.orig	2014-05-06 19:02:03.000000000 +0000
+++ libao2/ao_alsa.c
@@ -33,7 +33,9 @@
 #include <ctype.h>
 #include <math.h>
 #include <string.h>
+#if defined(__linux__) || defined (__sun)
 #include <alloca.h>
+#endif
 #define ALSA_PCM_NEW_HW_PARAMS_API
 #define ALSA_PCM_NEW_SW_PARAMS_API
 #include <alsa/asoundlib.h>
@@ -47,6 +49,10 @@
 #include "audio_out_internal.h"
 #include "libaf/af_format.h"
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 static const ao_info_t info =
 {
     "ALSA-0.9.x-1.x audio output",
