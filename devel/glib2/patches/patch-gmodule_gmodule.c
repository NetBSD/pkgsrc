$NetBSD: patch-gmodule_gmodule.c,v 1.3 2021/06/30 14:26:11 prlw1 Exp $

RTL_GLOBAL is a bug.
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/2171

--- gmodule/gmodule.c.orig	2021-06-10 18:57:57.268194400 +0000
+++ gmodule/gmodule.c
@@ -506,9 +506,8 @@ g_module_open (const gchar    *file_name
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
