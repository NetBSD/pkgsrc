$NetBSD: patch-src_java.desktop_unix_native_libpipewire_include_spa_utils_string.h,v 1.2 2026/08/14 12:52:05 ryoon Exp $

* Fix build with GCC 14. NetBSD has no uselocale().

--- src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h.orig	2026-07-23 23:33:34.000000000 +0000
+++ src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h
@@ -269,14 +269,20 @@ SPA_API_STRING float spa_strtof(const char *str, char 
 #endif
     float v;
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     if (SPA_UNLIKELY(locale == NULL))
         locale = newlocale(LC_ALL_MASK, "C", NULL);
     prev = uselocale(locale);
+#else
+    prev = LC_C_LOCALE;
 #endif
+#endif
     v = strtof(str, endptr);
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     uselocale(prev);
 #endif
+#endif
     return v;
 }
 
@@ -319,13 +325,19 @@ SPA_API_STRING double spa_strtod(const char *str, char
 #endif
     double v;
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     if (SPA_UNLIKELY(locale == NULL))
         locale = newlocale(LC_ALL_MASK, "C", NULL);
     prev = uselocale(locale);
+#else
+    prev = LC_C_LOCALE;
 #endif
+#endif
     v = strtod(str, endptr);
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     uselocale(prev);
+#endif
 #endif
     return v;
 }
