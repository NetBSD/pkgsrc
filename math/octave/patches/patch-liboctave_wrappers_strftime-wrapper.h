$NetBSD: patch-liboctave_wrappers_strftime-wrapper.h,v 1.2 2017/03/15 11:33:03 maya Exp $

Octave's wrapper breaks gnulib portability, netbsd doesn't have struct tm_zone,
use ifdefs to work around it

--- liboctave/wrappers/strftime-wrapper.h.orig	2016-11-13 15:16:10.000000000 +0000
+++ liboctave/wrappers/strftime-wrapper.h
@@ -35,7 +35,11 @@ extern "C" {
 
 extern size_t
 octave_strftime_wrapper (char *buf, size_t len, const char *fmt,
+#ifdef __NetBSD__
+                         const struct tm *t, timezone_t *tz, int ns);
+#else
                          const struct tm *t, struct tm_zone *tz, int ns);
+#endif
 
 #if defined __cplusplus
 }
