$NetBSD: patch-gmodule_gmodule.c,v 1.1 2018/10/08 10:12:06 prlw1 Exp $

RTLD_GLOBAL is a bug.
https://gitlab.gnome.org/GNOME/glib/issues/19

--- gmodule/gmodule.c.orig	2018-01-08 21:34:19.000000000 +0000
+++ gmodule/gmodule.c
@@ -207,8 +207,7 @@ struct _GModule
 static gpointer		_g_module_open		(const gchar	*file_name,
 						 gboolean	 bind_lazy,
 						 gboolean	 bind_local);
-static void		_g_module_close		(gpointer	 handle,
-						 gboolean	 is_unref);
+static void		_g_module_close		(gpointer	 handle);
 static gpointer		_g_module_self		(void);
 static gpointer		_g_module_symbol	(gpointer	 handle,
 						 const gchar	*symbol_name);
@@ -299,8 +298,7 @@ _g_module_open (const gchar	*file_name,
   return NULL;
 }
 static void
-_g_module_close	(gpointer	 handle,
-		 gboolean	 is_unref)
+_g_module_close	(gpointer	 handle)
 {
 }
 static gpointer
@@ -510,9 +508,8 @@ g_module_open (const gchar    *file_name
       if (!main_module)
 	{
 	  handle = _g_module_self ();
-/* On Android 64 bit, RTLD_DEFAULT is (void *)0x0
- * so it always fails to create main_module if file_name is NULL */
-#if !defined(__BIONIC__) || !defined(__LP64__)
+/* On Linux, handle == RTLD_DEFAULT is (void *)0x0 */
+#if G_MODULE_IMPL != G_MODULE_IMPL_DL
 	  if (handle)
 #endif
 	    {
@@ -617,7 +614,7 @@ g_module_open (const gchar    *file_name
       module = g_module_find_by_handle (handle);
       if (module)
 	{
-	  _g_module_close (module->handle, TRUE);
+	  _g_module_close (module->handle);
 	  module->ref_count++;
 	  g_module_set_error (NULL);
 	  
@@ -723,7 +720,7 @@ g_module_close (GModule *module)
 	}
       module->next = NULL;
       
-      _g_module_close (module->handle, FALSE);
+      _g_module_close (module->handle);
       g_free (module->file_name);
       g_free (module);
     }
