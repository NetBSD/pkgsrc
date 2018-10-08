$NetBSD: patch-gmodule_gmodule-dl.c,v 1.1 2018/10/08 10:12:06 prlw1 Exp $

RTLD_GLOBAL is a bug.
https://gitlab.gnome.org/GNOME/glib/issues/19

--- gmodule/gmodule-dl.c.orig	2018-01-08 21:34:19.000000000 +0000
+++ gmodule/gmodule-dl.c
@@ -106,46 +106,13 @@ _g_module_open (const gchar *file_name,
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
-_g_module_close (gpointer handle,
-		 gboolean is_unref)
+_g_module_close (gpointer handle)
 {
-  /* are there any systems out there that have dlopen()/dlclose()
-   * without a reference count implementation?
-   *
-   * See above for the Android special case
-   */
-#if defined(__BIONIC__)
-  is_unref = (handle != RTLD_DEFAULT);
-#else
-  is_unref |= 1;
-#endif
-
-  if (is_unref)
+  if (handle != RTLD_DEFAULT)
     {
       if (dlclose (handle) != 0)
 	g_module_set_error (fetch_dlerror (TRUE));
