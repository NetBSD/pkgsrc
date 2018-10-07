$NetBSD: patch-src_glx_dri__glx.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/glx/dri_glx.c.orig	2018-01-18 21:30:28.000000000 +0000
+++ src/glx/dri_glx.c
@@ -183,9 +183,21 @@ static struct driver_config_entry *drive
 /* Called as an atexit function. Otherwise, this would have to be called with
  * driver_config_mutex locked.
  */
+#if defined(HAVE_NOATEXIT)
+static Bool e_next_ever_null = False;
+
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 clear_driver_config_cache()
 {
+
+#if defined(HAVE_NOATEXIT)
+   if (!e_next_ever_null)
+      return;
+#endif
+
    while (driver_config_cache) {
       struct driver_config_entry *e = driver_config_cache;
       driver_config_cache = e->next;
@@ -276,7 +288,11 @@ glXGetDriverConfig(const char *driverNam
    driver_config_cache = e;
 
    if (!e->next)
+#if defined(HAVE_NOATEXIT)
+      e_next_ever_null = True;
+#else
       atexit(clear_driver_config_cache);
+#endif
 
 out:
    pthread_mutex_unlock(&driver_config_mutex);
