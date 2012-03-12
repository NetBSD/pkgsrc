$NetBSD: patch-extra_lib__include__ffmpeg__avio.h,v 1.1 2012/03/12 11:22:15 fhajny Exp $

SunOS already has offset_t defined.
--- extra_lib/include/ffmpeg/avio.h.orig	2007-05-30 15:54:08.000000000 +0000
+++ extra_lib/include/ffmpeg/avio.h
@@ -23,7 +23,9 @@
 
 /* output byte stream handling */
 
+#if !defined(__sun)
 typedef int64_t offset_t;
+#endif
 
 /* unbuffered I/O */
 
