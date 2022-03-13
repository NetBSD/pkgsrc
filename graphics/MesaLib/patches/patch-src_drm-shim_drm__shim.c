$NetBSD: patch-src_drm-shim_drm__shim.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

--- src/drm-shim/drm_shim.c.orig	2021-07-14 20:04:46.724922400 +0000
+++ src/drm-shim/drm_shim.c
@@ -162,7 +162,11 @@ drm_shim_override_file(const char *conte
    override->contents = strdup(contents);
 }
 
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 destroy_shim(void)
 {
    _mesa_set_destroy(opendir_set, NULL);
@@ -227,7 +231,9 @@ init_shim(void)
 
    drm_shim_device_init();
 
+#if !defined(HAVE_NOATEXIT)
    atexit(destroy_shim);
+#endif
 }
 
 /* Override libdrm's reading of various sysfs files for device enumeration. */
