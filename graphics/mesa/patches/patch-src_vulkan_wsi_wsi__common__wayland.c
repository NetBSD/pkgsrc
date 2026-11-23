$NetBSD: patch-src_vulkan_wsi_wsi__common__wayland.c,v 1.1 2026/11/23 10:29:52 adam Exp $

* Fix build under NetBSD.

--- src/vulkan/wsi/wsi_common_wayland.c.orig	2026-10-23 06:28:38.886516782 +0000
+++ src/vulkan/wsi/wsi_common_wayland.c
@@ -22,6 +22,13 @@
  * IN THE SOFTWARE.
  */
 
+/*
+ * NetBSD has no CLOCK_MONOTONIC_RAW.
+ */
+#if !defined(CLOCK_MONOTONIC_RAW)
+#define CLOCK_MONOTONIC_RAW	-1
+#endif
+
 #include <wayland-client.h>
 
 #include <assert.h>
