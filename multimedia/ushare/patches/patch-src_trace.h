$NetBSD: patch-src_trace.h,v 1.1 2012/12/25 21:05:50 joerg Exp $

--- src/trace.h.orig	2012-12-25 19:30:31.000000000 +0000
+++ src/trace.h
@@ -29,7 +29,7 @@ typedef enum {
 
 void print_log (log_level level, const char *format, ...)
   __attribute__ ((format (printf, 2, 3)));
-inline void start_log (void);
+void start_log (void);
 
 /* log_info
  * Normal print, to replace printf
