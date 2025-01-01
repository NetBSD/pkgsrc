$NetBSD: patch-src_common_utility.c,v 1.1 2025/01/01 14:06:17 ryoon Exp $

--- src/common/utility.c.orig	2025-01-01 13:54:43.932082793 +0000
+++ src/common/utility.c
@@ -135,17 +135,21 @@ gchar *dt_util_float_to_str(const gchar 
   setlocale (LC_NUMERIC, "C");
 #else
   locale_t nlocale = newlocale(LC_NUMERIC_MASK, "C", (locale_t) 0);
+#if !defined(__NetBSD__)
   locale_t locale = uselocale(nlocale);
 #endif
+#endif
 
   gchar *txt = g_strdup_printf(format, value);
 
 #if defined(WIN32)
   _configthreadlocale(_DISABLE_PER_THREAD_LOCALE);
 #else
+#if !defined(__NetBSD__)
   uselocale(locale);
   freelocale(nlocale);
 #endif
+#endif
   return txt;
 }
 
