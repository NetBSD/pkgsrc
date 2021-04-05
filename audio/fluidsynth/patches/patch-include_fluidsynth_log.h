$NetBSD: patch-include_fluidsynth_log.h,v 1.2 2021/04/05 10:54:16 wiz Exp $

Use the protected form to avoid conflicts with printf macros.

--- include/fluidsynth/log.h.orig	2021-03-27 17:35:00.000000000 +0000
+++ include/fluidsynth/log.h
@@ -85,7 +85,7 @@ FLUIDSYNTH_API void fluid_default_log_fu
 
 FLUIDSYNTH_API int fluid_log(int level, const char *fmt, ...)
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
-__attribute__ ((format (printf, 2, 3)))
+__attribute__ ((__format__ (__printf__, 2, 3)))
 #endif
 ;
 /* @} */
