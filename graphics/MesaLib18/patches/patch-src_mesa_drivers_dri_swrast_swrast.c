$NetBSD: patch-src_mesa_drivers_dri_swrast_swrast.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Fix build on older NetBSD w/o _SC_PHYS_PAGES.

--- src/mesa/drivers/dri/swrast/swrast.c.orig	2017-10-19 12:23:53.000000000 +0000
+++ src/mesa/drivers/dri/swrast/swrast.c
@@ -151,6 +151,12 @@ swrast_query_renderer_integer(__DRIscree
         size_t len = sizeof(system_memory_bytes);
         if (sysctl(mib, 2, &system_memory_bytes, &len, NULL, 0) != 0)
             return -1;
+#elif defined(HW_PHYSMEM64) && defined(__NetBSD__)
+        int mib[2] = { CTL_HW, HW_PHYSMEM64 };
+        uint64_t system_memory_bytes;
+        size_t len = sizeof(system_memory_bytes);
+        if (sysctl(mib, 2, &system_memory_bytes, &len, NULL, 0) != 0)
+            return -1;
 #elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGE_SIZE)
       /* XXX: Do we want to return the full amount of system memory ? */
       const long system_memory_pages = sysconf(_SC_PHYS_PAGES);
