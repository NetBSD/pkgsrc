$NetBSD: patch-tools_libs_foreignmemory_netbsd.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- tools/libs/foreignmemory/netbsd.c.orig	2020-05-14 14:19:32.000000000 +0200
+++ tools/libs/foreignmemory/netbsd.c	2020-05-25 17:36:19.241323602 +0200
@@ -19,7 +19,9 @@
 
 #include <unistd.h>
 #include <fcntl.h>
+#include <errno.h>
 #include <sys/mman.h>
+#include <sys/ioctl.h>
 
 #include "private.h"
 
@@ -66,15 +68,17 @@
     return close(fd);
 }
 
-void *osdep_map_foreign_batch(xenforeignmem_handle *fmem, uint32_t dom,
-                              void *addr, int prot, int flags,
-                              xen_pfn_t *arr, int num)
+void *osdep_xenforeignmemory_map(xenforeignmemory_handle *fmem,
+                                 uint32_t dom, void *addr,
+				 int prot, int flags, size_t num,
+				 const xen_pfn_t arr[/*num*/], int err[/*num*/])
+
 {
     int fd = fmem->fd;
-    privcmd_mmapbatch_t ioctlx;
-    addr = mmap(addr, num*XC_PAGE_SIZE, prot, flags | MAP_ANON | MAP_SHARED, -1, 0);
+    privcmd_mmapbatch_v2_t ioctlx;
+    addr = mmap(addr, num*PAGE_SIZE, prot, flags | MAP_ANON | MAP_SHARED, -1, 0);
     if ( addr == MAP_FAILED ) {
-        PERROR("osdep_map_foreign_batch: mmap failed");
+        PERROR("osdep_xenforeignmemory_map: mmap failed");
         return NULL;
     }
 
@@ -82,11 +86,12 @@
     ioctlx.dom=dom;
     ioctlx.addr=(unsigned long)addr;
     ioctlx.arr=arr;
-    if ( ioctl(fd, IOCTL_PRIVCMD_MMAPBATCH, &ioctlx) < 0 )
+    ioctlx.err=err;
+    if ( ioctl(fd, IOCTL_PRIVCMD_MMAPBATCH_V2, &ioctlx) < 0 )
     {
         int saved_errno = errno;
-        PERROR("osdep_map_foreign_batch: ioctl failed");
-        (void)munmap(addr, num*XC_PAGE_SIZE);
+        PERROR("osdep_xenforeignmemory_map: ioctl failed");
+        (void)munmap(addr, num*PAGE_SIZE);
         errno = saved_errno;
         return NULL;
     }
@@ -97,7 +102,58 @@
 int osdep_xenforeignmemory_unmap(xenforeignmemory_handle *fmem,
                                  void *addr, size_t num)
 {
-    return munmap(addr, num*XC_PAGE_SIZE);
+    return munmap(addr, num*PAGE_SIZE);
+}
+
+int osdep_xenforeignmemory_restrict(xenforeignmemory_handle *fmem,
+                                    domid_t domid)
+{
+    return 0;
+}
+
+int osdep_xenforeignmemory_unmap_resource(
+    xenforeignmemory_handle *fmem, xenforeignmemory_resource_handle *fres)
+{
+    return fres ? munmap(fres->addr, fres->nr_frames << PAGE_SHIFT) : 0;
+}
+
+int osdep_xenforeignmemory_map_resource(
+    xenforeignmemory_handle *fmem, xenforeignmemory_resource_handle *fres)
+{
+    privcmd_mmap_resource_t mr = {
+        .dom = fres->domid,
+        .type = fres->type,
+        .id = fres->id,
+        .idx = fres->frame,
+        .num = fres->nr_frames,
+    };
+    int rc;
+
+    fres->addr = mmap(fres->addr, fres->nr_frames << PAGE_SHIFT,
+                      fres->prot, fres->flags | MAP_ANON | MAP_SHARED, -1, 0);
+    if ( fres->addr == MAP_FAILED )
+        return -1;
+
+    mr.addr = (uintptr_t)fres->addr;
+
+    rc = ioctl(fmem->fd, IOCTL_PRIVCMD_MMAP_RESOURCE, &mr);
+    if ( rc )
+    {
+        int saved_errno;
+
+        if ( errno != fmem->unimpl_errno && errno != EOPNOTSUPP )
+            PERROR("ioctl failed");
+        else
+            errno = EOPNOTSUPP;
+
+        saved_errno = errno;
+        (void)osdep_xenforeignmemory_unmap_resource(fmem, fres);
+        errno = saved_errno;
+
+        return -1;
+    }
+
+    return 0;
 }
 
 /*
