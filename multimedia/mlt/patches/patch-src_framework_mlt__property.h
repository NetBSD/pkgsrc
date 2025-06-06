$NetBSD: patch-src_framework_mlt__property.h,v 1.5 2025/06/06 23:20:05 wiz Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_property.h.orig	2025-05-07 22:48:51.000000000 +0000
+++ src/framework/mlt_property.h
@@ -30,7 +30,7 @@
 #include <sys/param.h>
 #endif
 
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 #include <locale.h>
 typedef locale_t mlt_locale_t;
 #elif defined(__APPLE__) || (defined(__FreeBSD_version) && __FreeBSD_version >= 900506)
