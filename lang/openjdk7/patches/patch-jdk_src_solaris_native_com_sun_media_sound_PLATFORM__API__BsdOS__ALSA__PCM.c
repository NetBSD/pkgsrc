$NetBSD: patch-jdk_src_solaris_native_com_sun_media_sound_PLATFORM__API__BsdOS__ALSA__PCM.c,v 1.1 2015/01/09 16:29:04 rumko Exp $

On some platforms ESTRPIPE is not defined, make it equal to EPIPE.

--- jdk/src/solaris/native/com/sun/media/sound/PLATFORM_API_BsdOS_ALSA_PCM.c.orig	2014-11-02 07:18:19.000000000 +0000
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
