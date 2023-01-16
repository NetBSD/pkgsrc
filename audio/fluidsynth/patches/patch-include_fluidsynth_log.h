$NetBSD: patch-include_fluidsynth_log.h,v 1.3 2023/01/16 20:48:41 adam Exp $

Use the protected form to avoid conflicts with printf macros.

--- include/fluidsynth/log.h.orig	2022-12-28 11:43:59.000000000 +0000
+++ include/fluidsynth/log.h
@@ -85,7 +85,7 @@ FLUIDSYNTH_API void fluid_default_log_fu
 
 FLUIDSYNTH_API int fluid_log(int level, const char *fmt, ...)
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
-__attribute__ ((format (printf, 2, 3)))
+__attribute__ ((__format__ (__printf__, 2, 3)))
 #endif
 ;
 /** @} */
