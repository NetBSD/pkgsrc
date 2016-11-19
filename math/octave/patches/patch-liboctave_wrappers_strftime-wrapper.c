$NetBSD: patch-liboctave_wrappers_strftime-wrapper.c,v 1.1 2016/11/19 21:53:12 maya Exp $

Don't have struct tm_zone (in netbsd), instead use timezone_t as libgnu does

--- liboctave/wrappers/strftime-wrapper.c.orig	2016-11-13 15:16:10.000000000 +0000
+++ liboctave/wrappers/strftime-wrapper.c
@@ -36,7 +36,7 @@ along with Octave; see the file COPYING.
 
 size_t
 octave_strftime_wrapper (char *buf, size_t len, const char *fmt,
-                         const struct tm *t, struct tm_zone *tz, int ns)
+                         const struct tm *t, timezone_t *tz, int ns)
 {
   return nstrftime (buf, len, fmt, t, tz, ns);
 }
