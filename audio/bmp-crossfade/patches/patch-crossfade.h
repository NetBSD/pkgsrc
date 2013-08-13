$NetBSD: patch-crossfade.h,v 1.1 2013/08/13 00:45:50 khorben Exp $

--- crossfade.h.orig	2006-07-13 10:09:41.000000000 +0000
+++ crossfade.h
@@ -132,7 +132,11 @@
 #define FC_OFFSET_LOCK_OUT 2
 #define FC_OFFSET_CUSTOM   3
 
+#ifdef __NetBSD__
+#define DEFAULT_OSS_ALT_AUDIO_DEVICE "/dev/sound"
+#else
 #define DEFAULT_OSS_ALT_AUDIO_DEVICE "/dev/dsp"
+#endif
 #define DEFAULT_OSS_ALT_MIXER_DEVICE "/dev/mixer"
 #define DEFAULT_OP_CONFIG_STRING     "libOSS.so=0,1,2304,0; libdisk_writer.so=1,0,2304,1"
 #define DEFAULT_OP_NAME              "libOSS.so"
