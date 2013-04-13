$NetBSD: patch-glib_glib_gfileutils.c,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gfileutils.c.orig	2012-10-13 14:35:36.000000000 +0000
+++ glib/glib/gfileutils.c
@@ -2175,7 +2175,7 @@ g_path_skip_root (const gchar *file_name
 {
   g_return_val_if_fail (file_name != NULL, NULL);
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
   /* Skip \\server\share or //server/share */
   if (G_IS_DIR_SEPARATOR (file_name[0]) &&
       G_IS_DIR_SEPARATOR (file_name[1]) &&
@@ -2185,7 +2185,6 @@ g_path_skip_root (const gchar *file_name
       gchar *p;
       p = strchr (file_name + 2, G_DIR_SEPARATOR);
 
-#ifdef G_OS_WIN32
       {
         gchar *q;
 
@@ -2193,7 +2192,6 @@ g_path_skip_root (const gchar *file_name
         if (p == NULL || (q != NULL && q < p))
         p = q;
       }
-#endif
 
       if (p && p > file_name + 2 && p[1])
         {
