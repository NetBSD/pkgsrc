$NetBSD: patch-src_a68g_a68glib.c,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Fix build under NetBSD at least.

--- src/a68g/a68glib.c.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/a68g/a68glib.c
@@ -43,7 +43,9 @@ int snprintf (char *s, size_t n, const c
 {
   va_list ap;
   va_start (ap, format);
+#if 0
   int vsnprintf (char *, size_t, const char *, va_list);
+#endif
   int result = vsnprintf (s, n, format, ap);
   va_end (ap);
   return result;
