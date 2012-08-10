$NetBSD: patch-src_log.h,v 1.1 2012/08/10 18:03:02 joerg Exp $

--- src/log.h.orig	2012-08-10 11:56:47.000000000 +0000
+++ src/log.h
@@ -25,6 +25,6 @@ Levels_log;
 
 extern Levels_log log_level;
 
-inline void logPrintf(Levels_log level, char *fmt, ...);
+void logPrintf(Levels_log level, char *fmt, ...);
 
 #endif
