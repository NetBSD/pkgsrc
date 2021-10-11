$NetBSD: patch-gmodule_gmodule-dl.c,v 1.4 2021/10/11 10:03:47 cirnatdan Exp $

RTL_GLOBAL is a bug.
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/2171

--- gmodule/gmodule-dl.c.orig	2021-09-17 10:17:56.832962500 +0000
+++ gmodule/gmodule-dl.c
@@ -151,38 +151,13 @@ _g_module_open (const gchar *file_name,
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
-  lock_dlerror ();
-#if defined(__BIONIC__)
-  handle = RTLD_DEFAULT;
-#else
-  handle = dlopen (NULL, RTLD_GLOBAL | RTLD_LAZY);
-#endif
-  if (!handle)
-    g_module_set_error (fetch_dlerror (TRUE));
-  unlock_dlerror ();
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
       lock_dlerror ();
       if (dlclose (handle) != 0)
