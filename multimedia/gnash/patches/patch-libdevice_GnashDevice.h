$NetBSD: patch-libdevice_GnashDevice.h,v 1.1 2016/08/15 12:26:54 richard Exp $

Avoid enum name clash with NODEV, unfortunately defined in sys/types.h
and sys/params.h on solaris.

--- libdevice/GnashDevice.h.orig	2012-01-19 19:17:48.000000000 +0000
+++ libdevice/GnashDevice.h
@@ -45,6 +45,9 @@ struct GnashDevice
     /// The list of supported renders that use devices
     typedef enum {OPENVG, OPENGL, OPENGLES1, OPENGLES2, XORG, VAAPI} rtype_t;
     /// The list of supported device types
+#ifdef NODEV
+#undef NODEV
+#endif
     typedef enum {NODEV, EGL, DIRECTFB, X11, RAWFB} dtype_t;
     
     GnashDevice(int argc, char *argv[]);
