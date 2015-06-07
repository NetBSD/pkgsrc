$NetBSD: patch-src_mesa_drivers_dri_i965_intel__screen.c,v 1.2 2015/06/07 15:48:12 tnn Exp $

Fix build on older NetBSD w/o _SC_PHYS_PAGES.

--- src/mesa/drivers/dri/i965/intel_screen.c.orig	2015-06-07 10:06:53.000000000 +0000
+++ src/mesa/drivers/dri/i965/intel_screen.c
@@ -42,6 +42,10 @@
 #include "utils.h"
 #include "xmlpool.h"
 
+#ifdef HAVE_SYS_SYSCTL_H
+# include <sys/sysctl.h>
+#endif
+
 static const __DRIconfigOptionsExtension brw_config_options = {
    .base = { __DRI_CONFIG_OPTIONS, 1 },
    .xml =
@@ -829,6 +833,13 @@ brw_query_renderer_integer(__DRIscreen *
       const unsigned gpu_mappable_megabytes =
          (aper_size / (1024 * 1024)) * 3 / 4;
 
+#if defined(HW_PHYSMEM64)
+      int mib[2] = { CTL_HW, HW_PHYSMEM64 };
+      const uint64_t system_memory_bytes;
+      size_t len = sizeof(system_memory_bytes);
+      if (sysctl(mib, 2, &system_memory_bytes, &len, NULL, 0) != 0)
+         return -1;
+#else
       const long system_memory_pages = sysconf(_SC_PHYS_PAGES);
       const long system_page_size = sysconf(_SC_PAGE_SIZE);
 
@@ -837,6 +848,7 @@ brw_query_renderer_integer(__DRIscreen *
 
       const uint64_t system_memory_bytes = (uint64_t) system_memory_pages
          * (uint64_t) system_page_size;
+#endif
 
       const unsigned system_memory_megabytes =
          (unsigned) (system_memory_bytes / (1024 * 1024));
