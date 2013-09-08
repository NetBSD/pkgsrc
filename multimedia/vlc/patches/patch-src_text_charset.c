$NetBSD: patch-src_text_charset.c,v 1.1 2013/09/08 16:28:27 joerg Exp $

--- src/text/charset.c.orig	2013-05-15 20:27:52.000000000 +0000
+++ src/text/charset.c
@@ -78,6 +78,9 @@ char *vlc_fix_readdir( const char *psz_s
  */
 double us_strtod( const char *str, char **end )
 {
+#ifdef LC_C_LOCALE
+    return strtod_l(str, end, LC_C_LOCALE);
+#else
     locale_t loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
     locale_t oldloc = uselocale (loc);
     double res = strtod (str, end);
@@ -88,6 +91,7 @@ double us_strtod( const char *str, char 
         freelocale (loc);
     }
     return res;
+#endif
 }
 
 
@@ -97,6 +101,9 @@ double us_strtod( const char *str, char 
  */
 float us_strtof( const char *str, char **end )
 {
+#ifdef LC_C_LOCALE
+    return strtof_l(str, end, LC_C_LOCALE);
+#else
     locale_t loc = newlocale (LC_NUMERIC_MASK, "C", NULL);
     locale_t oldloc = uselocale (loc);
     float res = strtof (str, end);
@@ -107,6 +114,7 @@ float us_strtof( const char *str, char *
         freelocale (loc);
     }
     return res;
+#endif
 }
 
 
@@ -126,6 +134,14 @@ double us_atof( const char *str )
  */
 int us_asprintf( char **ret, const char *format, ... )
 {
+#ifdef LC_C_LOCALE
+    va_list ap;
+    int i_rc;
+    va_start( ap, format );
+    i_rc = vasprintf_l( ret, LC_C_LOCALE, format, ap );
+    va_end( ap );
+    return i_rc;
+#else
     va_list ap;
     locale_t loc = newlocale( LC_NUMERIC_MASK, "C", NULL );
     locale_t oldloc = uselocale( loc );
@@ -142,4 +158,5 @@ int us_asprintf( char **ret, const char 
     }
 
     return i_rc;
+#endif
 }
