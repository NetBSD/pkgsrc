$NetBSD: patch-include_fluidsynth_log.h,v 1.1 2019/12/19 23:59:56 joerg Exp $

Use the protected form to avoid conflicts with printf macros.

--- include/fluidsynth/log.h.orig	2019-12-19 23:29:25.082934836 +0000
+++ include/fluidsynth/log.h
@@ -79,7 +79,7 @@ FLUIDSYNTH_API void fluid_default_log_fu
 
 FLUIDSYNTH_API int fluid_log(int level, const char *fmt, ...)
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
-__attribute__ ((format (printf, 2, 3)))
+__attribute__ ((__format__ (__printf__, 2, 3)))
 #endif
 ;
 
