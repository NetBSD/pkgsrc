$NetBSD: patch-src_audio.h,v 1.1 2025/04/12 18:37:15 jmcneill Exp $

Fixup default audio device on NetBSD.

--- src/audio.h.orig	2025-04-12 18:27:57.541421369 +0000
+++ src/audio.h
@@ -390,6 +390,8 @@ struct audio_s {
 #define DEFAULT_ADEVICE	"default"	/* Use default device for ALSA. */
 #elif USE_SNDIO
 #define DEFAULT_ADEVICE	"default"	/* Use default device for sndio. */
+#elif defined(__NetBSD__)
+#define DEFAULT_ADEVICE "/dev/audio"	/* First audio device for OSS.  (NetBSD) */
 #else
 #define DEFAULT_ADEVICE	"/dev/dsp"	/* First audio device for OSS.  (FreeBSD) */
 #endif					
