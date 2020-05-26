$NetBSD: patch-tools_libs_foreignmemory_private.h,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- tools/libs/foreignmemory/private.h.orig	2019-12-17 15:23:09.000000000 +0100
+++ tools/libs/foreignmemory/private.h	2020-05-17 20:52:40.910407317 +0200
@@ -8,7 +8,13 @@
 #include <xentoolcore_internal.h>
 
 #include <xen/xen.h>
+
+#ifdef __NetBSD__
+#include <xen/xen.h>
+#include <xen/xenio.h>
+#else
 #include <xen/sys/privcmd.h>
+#endif
 
 #ifndef PAGE_SHIFT /* Mini-os, Yukk */
 #define PAGE_SHIFT           12
@@ -38,7 +44,7 @@
 
 #if defined(__NetBSD__) || defined(__sun__)
 /* Strictly compat for those two only only */
-void *compat_mapforeign_batch(xenforeignmem_handle *fmem, uint32_t dom,
+void *osdep_map_foreign_batch(xenforeignmemory_handle *fmem, uint32_t dom,
                               void *addr, int prot, int flags,
                               xen_pfn_t *arr, int num);
 #endif
@@ -54,7 +60,7 @@
     int flags;
 };
 
-#ifndef __linux__
+#if  !defined(__linux__) && !defined(__NetBSD__)
 static inline int osdep_xenforeignmemory_restrict(xenforeignmemory_handle *fmem,
                                                   domid_t domid)
 {
