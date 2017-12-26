$NetBSD: patch-lib_log.h,v 1.1 2017/12/26 11:27:39 he Exp $

Constify, to quiet type conversion warnings.

--- lib/log.h.orig	2003-12-23 04:22:53.000000000 +0000
+++ lib/log.h
@@ -194,7 +194,7 @@ LIBGIFT_EXPORT
 LIBGIFT_EXPORT
   void log_debug     (const char *fmt, ...) GIFT_FMTATTR (1, 2);
 LIBGIFT_EXPORT
-  void log_trace_pfx (char *pfx, char *file, int line, char *func, char *extra);
+  void log_trace_pfx (const char *pfx, const char *file, int line, const char *func, const char *extra);
 LIBGIFT_EXPORT
   void log_trace     (const char *fmt, ...) GIFT_FMTATTR (1, 2);
 
