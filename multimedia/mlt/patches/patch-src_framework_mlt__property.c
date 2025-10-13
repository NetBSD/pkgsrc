$NetBSD: patch-src_framework_mlt__property.c,v 1.4 2025/10/13 02:22:16 mrg Exp $

Avoid the strtod_l() etc code on NetBSD as well, it is attempts
to convert between "char *" and "locale_t" directly.


--- src/framework/mlt_property.c.orig	2025-05-07 15:48:51.000000000 -0700
+++ src/framework/mlt_property.c	2025-10-12 14:14:48.402329303 -0700
@@ -319,7 +319,7 @@ static int time_clock_to_frames(mlt_prop
     pos = strrchr(s, ':');
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
     char *orig_localename = NULL;
     if (locale) {
         // Protect damaging the global locale from a temporary locale on another thread.
@@ -334,7 +334,7 @@ static int time_clock_to_frames(mlt_prop
 #endif
 
     if (pos) {
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale)
             seconds = strtod_l(pos + 1, NULL, locale);
         else
@@ -350,7 +350,7 @@ static int time_clock_to_frames(mlt_prop
             minutes = atoi(s);
         }
     } else {
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale)
             seconds = strtod_l(s, NULL, locale);
         else
@@ -359,7 +359,7 @@ static int time_clock_to_frames(mlt_prop
     }
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
     if (locale) {
         // Restore the current locale
         setlocale(LC_NUMERIC, orig_localename);
@@ -523,7 +523,7 @@ static double mlt_property_atof(mlt_prop
         char *end = NULL;
         double result;
 
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale)
             result = strtod_l(value, &end, locale);
         else
@@ -546,7 +546,7 @@ static double mlt_property_atof(mlt_prop
             result /= 100.0;
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale) {
             // Restore the current locale
             setlocale(LC_NUMERIC, orig_localename);
@@ -1157,7 +1157,7 @@ int mlt_property_is_numeric(mlt_property
     if ((!result && self->types & mlt_prop_string) && self->prop_string) {
         char *p = NULL;
 
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale)
             strtod_l(self->prop_string, &p, locale);
         else
@@ -1178,7 +1178,7 @@ int mlt_property_is_numeric(mlt_property
             strtod(self->prop_string, &p);
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale) {
             // Restore the current locale
             setlocale(LC_NUMERIC, orig_localename);
@@ -1894,7 +1894,7 @@ mlt_rect mlt_property_get_rect(mlt_prope
         int count = 0;
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
         char *orig_localename = NULL;
         if (locale) {
             // Protect damaging the global locale from a temporary locale on another thread.
@@ -1910,7 +1910,7 @@ mlt_rect mlt_property_get_rect(mlt_prope
 
         while (*value) {
             double temp;
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(HAVE_STRTOD_L) && !defined(__OpenBSD__) && !defined(__NetBSD__)
             if (locale)
                 temp = strtod_l(value, &p, locale);
             else
@@ -1952,7 +1952,7 @@ mlt_rect mlt_property_get_rect(mlt_prope
         }
 
 #if !defined(__GLIBC__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(HAVE_STRTOD_L) \
-    && !defined(__OpenBSD__)
+    && !defined(__OpenBSD__) && !defined(__NetBSD__)
         if (locale) {
             // Restore the current locale
             setlocale(LC_NUMERIC, orig_localename);
