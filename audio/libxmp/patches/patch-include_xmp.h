$NetBSD: patch-include_xmp.h,v 1.1 2014/02/27 09:29:10 rxg Exp $

--- include/xmp.h.orig	2014-02-22 22:13:36.000000000 +0000
+++ include/xmp.h
@@ -79,7 +79,7 @@ extern "C" {
 #define XMP_MAX_ENV_POINTS	32	/* Max number of envelope points */
 #define XMP_MAX_MOD_LENGTH	256	/* Max number of patterns in module */
 #define XMP_MAX_CHANNELS	64	/* Max number of channels in module */
-#define XMP_MAX_SRATE		49170	/* max sampling rate (Hz) */
+#define XMP_MAX_SRATE		192000	/* max sampling rate (Hz) */
 #define XMP_MIN_SRATE		4000	/* min sampling rate (Hz) */
 #define XMP_MIN_BPM		20	/* min BPM */
 /* frame rate = (50 * bpm / 125) Hz */
