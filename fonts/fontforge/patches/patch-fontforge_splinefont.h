$NetBSD: patch-fontforge_splinefont.h,v 1.3 2019/09/02 14:45:37 nia Exp $

NetBSD does not implement uselocale().

--- fontforge/splinefont.h.orig	2019-07-22 10:10:01.551001000 +0000
+++ fontforge/splinefont.h
@@ -2625,17 +2625,33 @@ extern bool isSplinePointPartOfGuide( Sp
 
 extern void debug_printHint( StemInfo *h, char* msg );
 
-#if defined(_WIN32) || defined(__HAIKU__)
+#if defined(_WIN32) || defined(__HAIKU__) || defined(__NetBSD__)
 #define BAD_LOCALE_HACK
+#ifndef __NetBSD__
 typedef char* locale_t;
+#endif
+#ifndef LC_GLOBAL_LOCALE
 #define LC_GLOBAL_LOCALE ((locale_t)-1)
+#endif
+#ifndef LC_ALL_MASK
 #define LC_ALL_MASK LC_ALL
+#endif
+#ifndef LC_COLLATE_MASK
 #define LC_COLLATE_MASK LC_COLLATE
+#endif
+#ifndef LC_CTYPE_MASK
 #define LC_CTYPE_MASK LC_CTYPE
+#endif
+#ifndef LC_MONETARY_MASK
 #define LC_MONETARY_MASK LC_MONETARY
+#endif
+#ifndef LC_NUMERIC_MASK
 #define LC_NUMERIC_MASK LC_NUMERIC
+#endif
+#ifndef LC_TIME_MASK
 #define LC_TIME_MASK LC_TIME
 #endif
+#endif
 
 static inline void switch_to_c_locale(locale_t * tmplocale_p, locale_t * oldlocale_p) {
 #ifndef BAD_LOCALE_HACK
