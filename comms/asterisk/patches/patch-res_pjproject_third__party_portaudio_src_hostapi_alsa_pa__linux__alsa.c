$NetBSD: patch-res_pjproject_third__party_portaudio_src_hostapi_alsa_pa__linux__alsa.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/pjproject/third_party/portaudio/src/hostapi/alsa/pa_linux_alsa.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/pjproject/third_party/portaudio/src/hostapi/alsa/pa_linux_alsa.c
@@ -53,7 +53,7 @@
 #undef ALSA_PCM_NEW_HW_PARAMS_API
 #undef ALSA_PCM_NEW_SW_PARAMS_API
 
-#include <sys/poll.h>
+#include <poll.h>
 #include <string.h> /* strlen() */
 #include <limits.h>
 #include <math.h>
