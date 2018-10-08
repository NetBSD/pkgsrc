$NetBSD: patch-gmodule_gmodule-win32.c,v 1.1 2018/10/08 10:12:06 prlw1 Exp $

https://gitlab.gnome.org/GNOME/glib/issues/19

--- gmodule/gmodule-win32.c.orig	2018-01-08 21:34:19.000000000 +0000
+++ gmodule/gmodule-win32.c
@@ -105,8 +105,7 @@ _g_module_self (void)
 }
 
 static void
-_g_module_close (gpointer handle,
-		 gboolean is_unref)
+_g_module_close (gpointer handle)
 {
   if (handle != null_module_handle)
     if (!FreeLibrary (handle))
