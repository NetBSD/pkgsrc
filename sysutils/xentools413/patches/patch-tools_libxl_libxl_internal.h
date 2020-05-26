$NetBSD: patch-tools_libxl_libxl_internal.h,v 1.1 2020/05/26 11:12:11 bouyer Exp $

bump some timeouts to more reasonable values. 40s is not enough
if there is lots of them (e.g lots of network interfaces) and they
need to be serialized.

--- tools/libxl/libxl_internal.h.orig	2019-12-17 15:23:09.000000000 +0100
+++ tools/libxl/libxl_internal.h	2020-05-08 20:07:01.795038304 +0200
@@ -93,11 +93,11 @@
 #include "_libxl_types_internal_json.h"
 
 #define LIBXL_INIT_TIMEOUT 10
-#define LIBXL_DESTROY_TIMEOUT 10
-#define LIBXL_HOTPLUG_TIMEOUT 40
+#define LIBXL_DESTROY_TIMEOUT 180
+#define LIBXL_HOTPLUG_TIMEOUT 180
 /* QEMU may be slow to load and start due to a bug in Linux where the I/O
  * subsystem sometime produce high latency under load. */
-#define LIBXL_DEVICE_MODEL_START_TIMEOUT 60
+#define LIBXL_DEVICE_MODEL_START_TIMEOUT 180
 #define LIBXL_DEVICE_MODEL_SAVE_FILE XEN_LIB_DIR "/qemu-save" /* .$domid */
 #define LIBXL_DEVICE_MODEL_RESTORE_FILE XEN_LIB_DIR "/qemu-resume" /* .$domid */
 #define LIBXL_QMP_CMD_TIMEOUT 10
