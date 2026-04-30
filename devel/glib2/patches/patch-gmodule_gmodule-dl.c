$NetBSD: patch-gmodule_gmodule-dl.c,v 1.6 2026/04/30 16:23:46 tsutsui Exp $

- Avoid false g_module_symbol() failures in non glibc cases (PR/60215)

--- gmodule/gmodule-dl.c.orig	2026-03-16 13:53:50.000000000 +0000
+++ gmodule/gmodule-dl.c
@@ -292,6 +292,24 @@ _g_module_symbol (gpointer     handle,
   p = dlsym (handle, symbol_name);
   msg = fetch_dlerror (FALSE);
 #ifndef CYGWIN_WORKAROUND
+#if defined(__NetBSD__)
+  /*
+   * POSIX specifies that dlsym() returns a null pointer when the symbol
+   * cannot be found.  The dlerror()-based check is mainly for glibc
+   * implementations, which document successful NULL-valued symbol lookups.
+   *
+   * POSIX also says it is implementation-defined whether dlerror() is
+   * thread-safe.  NetBSD's dlerror() state is process-global, and
+   * !DLERROR_IS_THREADSAFE would only serialize GLib's own calls,
+   * not dlopen()/dlsym()/dlerror() calls outside GLib, such as
+   * libc NSS module probes etc.
+   *
+   * Therefore, do not turn a non-NULL dlsym() result into failure only
+   * because dlerror() has a non-NULL value.
+   */
+  if (p != NULL)
+    msg = NULL;
+#endif
   if (msg)
     g_module_set_error (msg);
   unlock_dlerror ();
