$NetBSD: patch-liboctave_wrappers_strftime-wrapper.c,v 1.2 2017/03/15 11:33:03 maya Exp $

Octave's wrapper breaks gnulib portability, netbsd doesn't have struct tm_zone,
use ifdefs to work around it

--- liboctave/wrappers/strftime-wrapper.c.orig	2016-11-13 15:16:10.000000000 +0000
+++ liboctave/wrappers/strftime-wrapper.c
@@ -36,7 +36,11 @@ along with Octave; see the file COPYING.
 
 size_t
 octave_strftime_wrapper (char *buf, size_t len, const char *fmt,
+#ifdef __NetBSD__
+                         const struct tm *t, timezone_t *tz, int ns)
+#else
                          const struct tm *t, struct tm_zone *tz, int ns)
+#endif
 {
   return nstrftime (buf, len, fmt, t, tz, ns);
 }
