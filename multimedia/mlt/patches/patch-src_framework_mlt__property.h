$NetBSD: patch-src_framework_mlt__property.h,v 1.4 2023/08/03 02:03:16 markd Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_property.h.orig	2023-07-28 18:06:26.000000000 +0000
+++ src/framework/mlt_property.h
@@ -30,7 +30,7 @@
 #include <sys/param.h>
 #endif
 
-#if (defined(__linux__) && !defined(__APPLE__))
+#if (defined(__linux__) && !defined(__APPLE__)) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 #include <locale.h>
 typedef locale_t mlt_locale_t;
 #elif defined(__APPLE__) || (defined(__FreeBSD_version) && __FreeBSD_version >= 900506)
