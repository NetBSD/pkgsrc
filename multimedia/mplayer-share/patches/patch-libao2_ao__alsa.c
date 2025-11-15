$NetBSD: patch-libao2_ao__alsa.c,v 1.2 2025/11/15 12:43:18 ryoon Exp $

Make this build on NetBSD.

--- libao2/ao_alsa.c.orig	2021-01-25 19:10:32.000000000 +0000
+++ libao2/ao_alsa.c
@@ -32,7 +32,9 @@
 #include <ctype.h>
 #include <math.h>
 #include <string.h>
+#if defined(__linux__) || defined (__sun)
 #include <alloca.h>
+#endif
 #define ALSA_PCM_NEW_HW_PARAMS_API
 #define ALSA_PCM_NEW_SW_PARAMS_API
 #include <alsa/asoundlib.h>
@@ -46,6 +48,10 @@
 #include "audio_out_internal.h"
 #include "libaf/af_format.h"
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 static const ao_info_t info =
 {
     "ALSA-0.9.x-1.x audio output",
@@ -308,7 +314,7 @@ static int try_open_device(const char *d
     } else {
       do
 	++args;
-      while (isspace(*args));
+      while (isspace((unsigned char)(*args)));
       if (*args == '\0') {
 	/* ":" but no parameters */
 	strcat(ac3_device, "AES0=6");
@@ -319,7 +325,7 @@ static int try_open_device(const char *d
 	/* parameters in config syntax: add it inside the { } block */
 	do
 	  --len;
-	while (len > 0 && isspace(ac3_device[len]));
+	while (len > 0 && isspace((unsigned char)(ac3_device[len])));
 	if (ac3_device[len] == '}')
 	  strcpy(ac3_device + len, " AES0=6}");
       }
