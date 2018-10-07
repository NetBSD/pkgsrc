$NetBSD: patch-src_egl_drivers_dri2_platform__x11.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Provide compat strndup for older Darwin.

* From FreeBSD ports 18.0.0:
work-around for https://bugs.freedesktop.org/show_bug.cgi?id=100627

Mon Apr 10 19:14:48 2017 UTC
DRI3 remains enabled at compile time, but it is now disabled at
runtime for stock FreeBSD.  Set LIBGL_DRI3_ENABLE in the
environment to enable DRI3.
This change was made to work around a problem in libEGL,
which fails to fall back to using DRI2 when run on a system
without DRI3 support.

* Added logging statement to note dri3 initialization being invoked.

--- src/egl/drivers/dri2/platform_x11.c.orig	2018-02-09 02:17:57.000000000 +0000
+++ src/egl/drivers/dri2/platform_x11.c
@@ -608,6 +608,23 @@ dri2_x11_local_authenticate(struct dri2_
    return EGL_TRUE;
 }
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+static char *
+strndup(const char *s, int length)
+{
+   char *d;
+
+   d = malloc(length + 1);
+   if (d == NULL)
+      return NULL;
+
+   memcpy(d, s, length);
+   d[length] = '\0';
+
+   return d;
+}
+#endif
+
 static EGLBoolean
 dri2_x11_connect(struct dri2_egl_display *dri2_dpy)
 {
@@ -1466,8 +1483,15 @@ dri2_initialize_x11(_EGLDriver *drv, _EG
 
    if (!disp->Options.ForceSoftware) {
 #ifdef HAVE_DRI3
-      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false))
+#if ((defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined(__DRM_NEXT__)) || defined(__DragonFly__) || defined(__NetBSD__)
+      if (env_var_as_boolean("LIBGL_DRI3_ENABLE", false))
+#endif
+      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false)) {
+         _eglLog(_EGL_INFO, "platform_x11.c: calling dri2_initialize_x11_dri3\n");
          initialized = dri2_initialize_x11_dri3(drv, disp);
+         if (initialized)
+            _eglLog(_EGL_INFO, "platform_x11.c: initialized by dri2_initialize_x11_dri3\n");
+      }
 #endif
 
       if (!initialized)
