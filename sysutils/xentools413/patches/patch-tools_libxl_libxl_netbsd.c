$NetBSD: patch-tools_libxl_libxl_netbsd.c,v 1.1 2020/08/27 08:22:33 bouyer Exp $

--- tools/libxl/libxl_netbsd.c.orig	2020-08-26 21:55:50.587030608 +0200
+++ tools/libxl/libxl_netbsd.c	2020-08-26 21:56:05.491231282 +0200
@@ -110,7 +110,7 @@
 
 libxl_device_model_version libxl__default_device_model(libxl__gc *gc)
 {
-    return LIBXL_DEVICE_MODEL_VERSION_QEMU_XEN_TRADITIONAL;
+    return LIBXL_DEVICE_MODEL_VERSION_QEMU_XEN;
 }
 
 int libxl__pci_numdevs(libxl__gc *gc)
