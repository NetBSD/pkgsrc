$NetBSD: patch-gmodule_gmodule-ar.c,v 1.1 2018/10/08 10:12:06 prlw1 Exp $

https://gitlab.gnome.org/GNOME/glib/issues/19

--- gmodule/gmodule-ar.c.orig	2017-07-13 23:03:39.000000000 +0000
+++ gmodule/gmodule-ar.c
@@ -141,19 +141,10 @@ _g_module_self (void)
 }
 
 static void
-_g_module_close (gpointer handle,
-		 gboolean is_unref)
+_g_module_close (gpointer handle)
 {
-  /* are there any systems out there that have dlopen()/dlclose()
-   * without a reference count implementation?
-   */
-  is_unref |= 1;
-  
-  if (is_unref)
-    {
-      if (dlclose (handle) != 0)
-	g_module_set_error (fetch_dlerror (TRUE));
-    }
+  if (dlclose (handle) != 0)
+    g_module_set_error (fetch_dlerror (TRUE));
 }
 
 static gpointer
