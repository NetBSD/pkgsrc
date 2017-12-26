$NetBSD: patch-lib_log.c,v 1.1 2017/12/26 11:27:39 he Exp $

Constify, to quiet type conversion warnings.

--- lib/log.c.orig	2004-01-15 14:02:11.000000000 +0000
+++ lib/log.c
@@ -237,7 +237,7 @@ void log_debug (const char *fmt, ...)
 	log_print (LOG_DEBUG, buf);
 }
 
-void log_trace_pfx (char *pfx, char *file, int line, char *func, char *extra)
+void log_trace_pfx (const char *pfx, const char *file, int line, const char *func, const char *extra)
 {
 	free (trace_pfx);
 	trace_pfx   = STRDUP (pfx);
