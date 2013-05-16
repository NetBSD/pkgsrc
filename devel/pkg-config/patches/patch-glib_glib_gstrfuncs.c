$NetBSD: patch-glib_glib_gstrfuncs.c,v 1.1 2013/05/16 13:55:42 adam Exp $

Fix for missing function errors when newlocale() is not defined.

--- /tmp/pkgsrc/devel/pkg-config/work/pkg-config-0.28/glib/glib/gstrfuncs.c.orig	2013-05-16 13:04:54.000000000 +0000
+++ /tmp/pkgsrc/devel/pkg-config/work/pkg-config-0.28/glib/glib/gstrfuncs.c
@@ -317,22 +317,22 @@ static const guint16 ascii_table_data[25
 
 const guint16 * const g_ascii_table = ascii_table_data;
 
-#ifdef HAVE_NEWLOCALE
 static locale_t
 get_C_locale (void)
 {
   static gsize initialized = FALSE;
   static locale_t C_locale = NULL;
 
+#ifdef HAVE_NEWLOCALE
   if (g_once_init_enter (&initialized))
     {
       C_locale = newlocale (LC_ALL_MASK, "C", NULL);
       g_once_init_leave (&initialized, TRUE);
     }
+#endif
 
   return C_locale;
 }
-#endif
 
 /**
  * g_strdup:
