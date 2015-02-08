$NetBSD: patch-jdk_src_solaris_native_com_sun_media_sound_PLATFORM__API__BsdOS__ALSA__PCM.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

On some platforms ESTRPIPE is not defined, make it equal to EPIPE.

--- jdk/src/solaris/native/com/sun/media/sound/PLATFORM_API_BsdOS_ALSA_PCM.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/com/sun/media/sound/PLATFORM_API_BsdOS_ALSA_PCM.c
@@ -30,6 +30,10 @@
 #include "PLATFORM_API_BsdOS_ALSA_CommonUtils.h"
 #include "DirectAudio.h"
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 #if USE_DAUDIO == TRUE
 
 // GetPosition method 1: based on how many bytes are passed to the kernel driver
