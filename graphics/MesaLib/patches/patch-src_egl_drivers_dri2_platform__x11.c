$NetBSD: patch-src_egl_drivers_dri2_platform__x11.c,v 1.2 2016/05/18 12:55:28 wiz Exp $

Provide compat strndup for older Darwin.

--- src/egl/drivers/dri2/platform_x11.c.orig	2016-05-05 12:59:22.000000000 +0000
+++ src/egl/drivers/dri2/platform_x11.c
@@ -591,6 +591,23 @@ dri2_x11_local_authenticate(struct dri2_
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
