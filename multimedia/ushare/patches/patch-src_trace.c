$NetBSD: patch-src_trace.c,v 1.1 2012/12/25 21:05:49 joerg Exp $

--- src/trace.c.orig	2012-12-25 19:30:21.000000000 +0000
+++ src/trace.c
@@ -57,7 +57,7 @@ print_log (log_level level, const char *
   va_end (va);
 }
 
-inline void
+void
 start_log (void)
 {
   openlog (PACKAGE_NAME, LOG_PID, LOG_DAEMON);
