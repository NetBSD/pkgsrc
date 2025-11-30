$NetBSD: patch-src_framework_mlt__property.c,v 1.5 2025/11/30 10:10:03 markd Exp $

Avoid the strtod_l() etc code on NetBSD as well, it is attempts
to convert between "char *" and "locale_t" directly.


--- src/framework/mlt_property.c.orig	2025-11-05 15:41:13.000000000 +0000
+++ src/framework/mlt_property.c
@@ -38,13 +38,13 @@
 #include <string.h>
 
 // Platforms with native strtod_l support
-#if defined(__GLIBC__) || defined(__APPLE__) || (defined(HAVE_STRTOD_L) && !defined(__OpenBSD__))
+#if defined(__GLIBC__) || defined(__APPLE__) || (defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__))
 #define HAVE_LOCALE_STRTOD_L 1
 #endif
 
 // Platforms requiring manual locale handling (excluding Windows)
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define NEED_LOCALE_SAVE_RESTORE 1
 #endif
 
@@ -562,7 +562,7 @@ static double mlt_property_atof(mlt_prop
         if (locale)
             result = strtod_l(value, &end, locale);
         else
-#elif !defined(_WIN32)
+#elif !defined(_WIN32) && !defined(__NetBSD__)
         if (locale) {
             // Protect damaging the global locale from a temporary locale on another thread.
             pthread_mutex_lock(&self->mutex);
@@ -1197,7 +1197,7 @@ int mlt_property_is_numeric(mlt_property
         if (locale)
             strtod_l(self->prop_string, &p, locale);
         else
-#elif !defined(_WIN32)
+#elif !defined(_WIN32) && !defined(__NetBSD__)
         if (locale) {
             // Protect damaging the global locale from a temporary locale on another thread.
             pthread_mutex_lock(&self->mutex);
