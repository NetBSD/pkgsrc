$NetBSD: patch-tools_libs_foreignmemory_private.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libs/foreignmemory/private.h.orig	2017-03-24 18:38:28.000000000 +0100
+++ tools/libs/foreignmemory/private.h	2017-03-24 18:52:19.000000000 +0100
@@ -34,7 +34,7 @@
 
 #if defined(__NetBSD__) || defined(__sun__)
 /* Strictly compat for those two only only */
-void *compat_mapforeign_batch(xenforeignmem_handle *fmem, uint32_t dom,
+void *osdep_map_foreign_batch(xenforeignmemory_handle *fmem, uint32_t dom,
                               int prot, xen_pfn_t *arr, int num);
 #endif
 
