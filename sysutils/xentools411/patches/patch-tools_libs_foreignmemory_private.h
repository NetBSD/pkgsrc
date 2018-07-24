$NetBSD: patch-tools_libs_foreignmemory_private.h,v 1.1 2018/07/24 13:40:11 bouyer Exp $

--- tools/libs/foreignmemory/private.h.orig	2018-04-17 19:21:31.000000000 +0200
+++ tools/libs/foreignmemory/private.h	2018-04-23 17:09:20.000000000 +0200
@@ -37,7 +37,7 @@
 
 #if defined(__NetBSD__) || defined(__sun__)
 /* Strictly compat for those two only only */
-void *compat_mapforeign_batch(xenforeignmem_handle *fmem, uint32_t dom,
+void *osdep_map_foreign_batch(xenforeignmemory_handle *fmem, uint32_t dom,
                               void *addr, int prot, int flags,
                               xen_pfn_t *arr, int num);
 #endif
