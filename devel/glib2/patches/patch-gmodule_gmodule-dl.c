$NetBSD: patch-gmodule_gmodule-dl.c,v 1.3 2021/06/30 14:26:11 prlw1 Exp $

RTL_GLOBAL is a bug.
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/2171

--- gmodule/gmodule-dl.c.orig	2021-06-10 18:57:57.268194400 +0000
+++ gmodule/gmodule-dl.c
@@ -106,36 +106,13 @@ _g_module_open (const gchar *file_name,
 static gpointer
 _g_module_self (void)
 {
-  gpointer handle;
-  
-  /* to query symbols from the program itself, special link options
-   * are required on some systems.
-   */
-
-  /* On Android 32 bit (i.e. not __LP64__), dlopen(NULL)
-   * does not work reliable and generally no symbols are found
-   * at all. RTLD_DEFAULT works though.
-   * On Android 64 bit, dlopen(NULL) seems to work but dlsym(handle)
-   * always returns 'undefined symbol'. Only if RTLD_DEFAULT or 
-   * NULL is given, dlsym returns an appropriate pointer.
-   */
-#if defined(__BIONIC__)
-  handle = RTLD_DEFAULT;
-#else
-  handle = dlopen (NULL, RTLD_GLOBAL | RTLD_LAZY);
-#endif
-  if (!handle)
-    g_module_set_error (fetch_dlerror (TRUE));
-  
-  return handle;
+  return RTLD_DEFAULT;
 }
 
 static void
 _g_module_close (gpointer handle)
 {
-#if defined(__BIONIC__)
   if (handle != RTLD_DEFAULT)
-#endif
     {
       if (dlclose (handle) != 0)
 	g_module_set_error (fetch_dlerror (TRUE));
