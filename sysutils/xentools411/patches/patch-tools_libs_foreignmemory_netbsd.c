$NetBSD: patch-tools_libs_foreignmemory_netbsd.c,v 1.1 2018/07/24 13:40:11 bouyer Exp $

--- tools/libs/foreignmemory/netbsd.c.orig	2018-04-17 19:21:31.000000000 +0200
+++ tools/libs/foreignmemory/netbsd.c	2018-04-23 15:31:28.000000000 +0200
@@ -19,7 +19,9 @@
 
 #include <unistd.h>
 #include <fcntl.h>
+#include <errno.h>
 #include <sys/mman.h>
+#include <sys/ioctl.h>
 
 #include "private.h"
 
@@ -66,13 +68,13 @@
     return close(fd);
 }
 
-void *osdep_map_foreign_batch(xenforeignmem_handle *fmem, uint32_t dom,
+void *osdep_map_foreign_batch(xenforeignmemory_handle *fmem, uint32_t dom,
                               void *addr, int prot, int flags,
                               xen_pfn_t *arr, int num)
 {
     int fd = fmem->fd;
     privcmd_mmapbatch_t ioctlx;
-    addr = mmap(addr, num*XC_PAGE_SIZE, prot, flags | MAP_ANON | MAP_SHARED, -1, 0);
+    addr = mmap(addr, num*PAGE_SIZE, prot, flags | MAP_ANON | MAP_SHARED, -1, 0);
     if ( addr == MAP_FAILED ) {
         PERROR("osdep_map_foreign_batch: mmap failed");
         return NULL;
@@ -86,7 +88,7 @@
     {
         int saved_errno = errno;
         PERROR("osdep_map_foreign_batch: ioctl failed");
-        (void)munmap(addr, num*XC_PAGE_SIZE);
+        (void)munmap(addr, num*PAGE_SIZE);
         errno = saved_errno;
         return NULL;
     }
@@ -97,7 +99,7 @@
 int osdep_xenforeignmemory_unmap(xenforeignmemory_handle *fmem,
                                  void *addr, size_t num)
 {
-    return munmap(addr, num*XC_PAGE_SIZE);
+    return munmap(addr, num*PAGE_SIZE);
 }
 
 /*
