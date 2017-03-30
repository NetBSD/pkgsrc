$NetBSD: patch-tools_libs_call_netbsd.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libs/call/netbsd.c.orig	2017-03-24 18:29:45.000000000 +0100
+++ tools/libs/call/netbsd.c	2017-03-24 18:34:05.000000000 +0100
@@ -19,12 +19,14 @@
  * Split from xc_netbsd.c
  */
 
-#include "xc_private.h"
 
 #include <unistd.h>
 #include <fcntl.h>
 #include <malloc.h>
+#include <errno.h>
 #include <sys/mman.h>
+#include <sys/ioctl.h>
+#include "private.h"
 
 int osdep_xencall_open(xencall_handle *xcall)
 {
@@ -69,12 +71,13 @@
     return close(fd);
 }
 
-void *osdep_alloc_hypercall_buffer(xencall_handle *xcall, size_t npages)
+void *osdep_alloc_pages(xencall_handle *xcall, size_t npages)
 {
-    size_t size = npages * XC_PAGE_SIZE;
+    size_t size = npages * PAGE_SIZE;
     void *p;
+    int ret;
 
-    ret = posix_memalign(&p, XC_PAGE_SIZE, size);
+    ret = posix_memalign(&p, PAGE_SIZE, size);
     if ( ret != 0 || !p )
         return NULL;
 
@@ -86,14 +89,13 @@
     return p;
 }
 
-void osdep_free_hypercall_buffer(xencall_handle *xcall, void *ptr,
-                                 size_t npages)
+void osdep_free_pages(xencall_handle *xcall, void *ptr, size_t npages)
 {
-    (void) munlock(ptr, npages * XC_PAGE_SIZE);
+    (void) munlock(ptr, npages * PAGE_SIZE);
     free(ptr);
 }
 
-int do_xen_hypercall(xencall_handle *xcall, privcmd_hypercall_t *hypercall)
+int osdep_hypercall(xencall_handle *xcall, privcmd_hypercall_t *hypercall)
 {
     int fd = xcall->fd;
     int error = ioctl(fd, IOCTL_PRIVCMD_HYPERCALL, hypercall);
