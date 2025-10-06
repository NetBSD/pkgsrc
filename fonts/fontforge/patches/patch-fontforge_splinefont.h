$NetBSD: patch-fontforge_splinefont.h,v 1.5 2025/10/06 19:59:04 wiz Exp $

Chunk 1: Use proper type for iconv(3) arguments.
https://github.com/fontforge/fontforge/pull/5637

Others: NetBSD does not implement uselocale().
https://github.com/fontforge/fontforge/pull/5638

--- fontforge/splinefont.h.orig	2023-01-01 05:25:39.000000000 +0000
+++ fontforge/splinefont.h
@@ -999,8 +999,8 @@ typedef struct enc {
     int iso_2022_escape_len;
     int low_page, high_page;
     char *iconv_name;	/* For compatibility to old versions we might use a different name from that used by iconv. */
-    iconv_t *tounicode;
-    iconv_t *fromunicode;
+    iconv_t tounicode;
+    iconv_t fromunicode;
     int (*tounicode_func)(int);
     int (*fromunicode_func)(int);
     unsigned int is_temporary: 1;	/* freed when the map gets freed */
@@ -2630,17 +2630,33 @@ extern bool isSplinePointPartOfGuide( Sp
 
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
