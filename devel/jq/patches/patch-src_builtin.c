$NetBSD: patch-src_builtin.c,v 1.3 2025/06/22 06:16:19 kim Exp $

Fixes CVE-2025-49014 which was introduced in 1.8.0
https://github.com/jqlang/jq/commit/499c91bca9d4d027833bc62787d1bb075c03680e.patch

--- src/builtin.c.orig	2025-06-01 05:58:31.000000000 +0000
+++ src/builtin.c	2025-06-22 06:08:48.067551402 +0000
@@ -1769,6 +1769,7 @@
     return ret_error(b, jv_string("strftime/1 requires parsed datetime inputs"));
 
   const char *fmt = jv_string_value(b);
+  int fmt_not_empty = *fmt != '\0';
   size_t max_size = strlen(fmt) + 100;
   char *buf = jv_mem_alloc(max_size);
 #ifdef __APPLE__
@@ -1789,7 +1790,7 @@
 #endif
   jv_free(b);
   /* POSIX doesn't provide errno values for strftime() failures; weird */
-  if ((n == 0 && *fmt) || n > max_size) {
+  if ((n == 0 && fmt_not_empty) || n > max_size) {
     free(buf);
     return jv_invalid_with_msg(jv_string("strftime/1: unknown system failure"));
   }
@@ -1818,12 +1819,13 @@
   if (!jv2tm(a, &tm, 1))
     return ret_error(b, jv_string("strflocaltime/1 requires parsed datetime inputs"));
   const char *fmt = jv_string_value(b);
+  int fmt_not_empty = *fmt != '\0';
   size_t max_size = strlen(fmt) + 100;
   char *buf = jv_mem_alloc(max_size);
   size_t n = strftime(buf, max_size, fmt, &tm);
   jv_free(b);
   /* POSIX doesn't provide errno values for strftime() failures; weird */
-  if ((n == 0 && *fmt) || n > max_size) {
+  if ((n == 0 && fmt_not_empty) || n > max_size) {
     free(buf);
     return jv_invalid_with_msg(jv_string("strflocaltime/1: unknown system failure"));
   }
