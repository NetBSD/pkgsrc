$NetBSD: patch-libxl_libxl_internal.h,v 1.1 2017/03/21 22:52:52 bouyer Exp $

bump some timeouts to more reasonable values. 40s is not enough
if there is lots of them (e.g lots of network interfaces) and they
need to be serialized.

--- libxl/libxl_internal.h.orig	2017-03-21 23:13:59.000000000 +0100
+++ libxl/libxl_internal.h	2017-03-21 23:14:47.000000000 +0100
@@ -85,11 +85,11 @@
 #include "_libxl_types_internal_json.h"
 
 #define LIBXL_INIT_TIMEOUT 10
-#define LIBXL_DESTROY_TIMEOUT 10
-#define LIBXL_HOTPLUG_TIMEOUT 40
+#define LIBXL_DESTROY_TIMEOUT 120
+#define LIBXL_HOTPLUG_TIMEOUT 120
 /* QEMU may be slow to load and start due to a bug in Linux where the I/O
  * subsystem sometime produce high latency under load. */
-#define LIBXL_DEVICE_MODEL_START_TIMEOUT 60
+#define LIBXL_DEVICE_MODEL_START_TIMEOUT 120
 #define LIBXL_DEVICE_MODEL_RESTORE_FILE "/var/lib/xen/qemu-resume" /* .$domid */
 #define LIBXL_STUBDOM_START_TIMEOUT 30
 #define LIBXL_QEMU_BODGE_TIMEOUT 2
