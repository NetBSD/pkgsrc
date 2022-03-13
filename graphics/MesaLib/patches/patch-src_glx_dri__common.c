$NetBSD: patch-src_glx_dri__common.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/glx/dri_common.c.orig	2021-07-14 20:04:55.743010300 +0000
+++ src/glx/dri_common.c
@@ -690,9 +690,19 @@ static struct driver_config_entry *drive
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
+#if defined(HAVE_NOATEXIT)
+   if (!e_next_ever_null)
+      return;
+#endif
    while (driver_config_cache) {
       struct driver_config_entry *e = driver_config_cache;
       driver_config_cache = e->next;
@@ -777,7 +787,11 @@ glXGetDriverConfig(const char *driverNam
    driver_config_cache = e;
 
    if (!e->next)
+#if defined(HAVE_NOATEXIT)
+      e_next_ever_null = True;
+#else
       atexit(clear_driver_config_cache);
+#endif
 
 out:
    pthread_mutex_unlock(&driver_config_mutex);
