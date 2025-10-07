$NetBSD: patch-src_java.desktop_unix_native_libpipewire_include_spa_utils_string.h,v 1.1 2025/10/07 14:12:22 ryoon Exp $

* Fix build with GCC 14. NetBSD has no uselocale().

--- src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h.orig	2025-10-07 10:23:27.815113122 +0000
+++ src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h
@@ -269,14 +269,20 @@ SPA_API_STRING float spa_strtof(const ch
 #endif
     float v;
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     if (SPA_UNLIKELY(locale == NULL))
         locale = newlocale(LC_ALL_MASK, "C", NULL);
     prev = uselocale(locale);
+#else
+    prev = LC_C_LOCALE;
+#endif
 #endif
     v = strtof(str, endptr);
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     uselocale(prev);
 #endif
+#endif
     return v;
 }
 
@@ -319,14 +325,20 @@ SPA_API_STRING double spa_strtod(const c
 #endif
     double v;
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     if (SPA_UNLIKELY(locale == NULL))
         locale = newlocale(LC_ALL_MASK, "C", NULL);
     prev = uselocale(locale);
+#else
+    prev = LC_C_LOCALE;
+#endif
 #endif
     v = strtod(str, endptr);
 #ifndef __LOCALE_C_ONLY
+#if !defined(__NetBSD__)
     uselocale(prev);
 #endif
+#endif
     return v;
 }
 
