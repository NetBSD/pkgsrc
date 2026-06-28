$NetBSD: patch-src_builtin.c,v 1.5 2026/06/28 15:41:12 wiz Exp $

Workaround for timezone problem.
https://github.com/jqlang/jq/issues/3568

--- src/builtin.c.orig	2026-06-20 13:36:30.000000000 +0000
+++ src/builtin.c
@@ -1835,7 +1835,7 @@ static jv f_strftime(jq_state *jq, jv a, jv b) {
   int fmt_not_empty = *fmt != '\0';
   size_t max_size = strlen(fmt) + 100;
   char *buf = jv_mem_alloc(max_size);
-#if defined(__APPLE__) || defined(__sun)
+#if defined(__APPLE__) || defined(__sun) || defined(__NetBSD__)
   /* Apple Libc (as of version 1669.40.2) contains a bug which causes it to
    * ignore the `tm.tm_gmtoff` in favor of the global timezone. To print the
    * proper timezone offset we temporarily switch the TZ to UTC. */
@@ -1848,7 +1848,7 @@ static jv f_strftime(jq_state *jq, jv a, jv b) {
   tzset();
 #endif
   size_t n = strftime(buf, max_size, fmt, &tm);
-#if defined(__APPLE__) || defined(__sun)
+#if defined(__APPLE__) || defined(__sun) || defined(__NetBSD__)
   if (tz) {
     setenv("TZ", tz, 1);
     free(tz);
