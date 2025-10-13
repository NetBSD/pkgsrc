$NetBSD: patch-import_mpg123.h,v 1.1 2025/10/13 03:21:20 mrg Exp $

Copy a couple of deprecated headers from lame.h to fix the GCC 14 build.
The functions are present in libmp3lame, but not visible in the header
without patching it directly.


--- import/mpg123.h.orig	2011-11-19 08:50:23.000000000 -0800
+++ import/mpg123.h	2025-10-12 20:10:32.047909853 -0700
@@ -41,6 +41,17 @@ int lame_decode_fromfile(FILE * fd, shor
 
 int buf_probe_mp3(unsigned char *_buf, int len, ProbeTrackInfo *pcm);
 
+#ifdef DEPRECATED_OR_OBSOLETE_CODE_REMOVED
+/* XXXMRG - duplicate hidden lame.h stuff. */
+int lame_decode_init(void);
+int lame_decode1_headers(
+        unsigned char*   mp3buf,
+        int              len,
+        short            pcm_l[],
+        short            pcm_r[],
+        mp3data_struct*  mp3data );
+#endif
+
 #endif  // HAVE_LAME
 
 #endif
