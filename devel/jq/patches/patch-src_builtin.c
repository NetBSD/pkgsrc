$NetBSD: patch-src_builtin.c,v 1.7 2026/07/02 15:26:35 wiz Exp $

Workaround for timezone problem.
https://github.com/jqlang/jq/issues/3568

--- src/builtin.c.orig	2026-06-20 13:36:30.000000000 +0000
+++ src/builtin.c
@@ -1847,7 +1847,13 @@ static jv f_strftime(jq_state *jq, jv a, jv b) {
    * account ... */
   tzset();
 #endif
+#ifdef __NetBSD__
+  timezone_t tz_utc = tzalloc("UTC");
+  size_t n = strftime_z(tz_utc, buf, max_size, fmt, &tm);
+  tzfree(tz_utc);
+#else
   size_t n = strftime(buf, max_size, fmt, &tm);
+#endif
 #if defined(__APPLE__) || defined(__sun)
   if (tz) {
     setenv("TZ", tz, 1);
