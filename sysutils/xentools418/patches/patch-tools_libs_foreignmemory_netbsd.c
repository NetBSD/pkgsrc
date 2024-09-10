$NetBSD: patch-tools_libs_foreignmemory_netbsd.c,v 1.1 2024/09/10 12:40:15 bouyer Exp $
Set O_CLOEXEC if requested; (from libs/foreignmemory/freebsd.c)

--- tools/libs/foreignmemory/netbsd.c.orig	2024-04-12 16:58:08.041146845 +0200
+++ tools/libs/foreignmemory/netbsd.c	2024-04-12 16:58:33.613393138 +0200
@@ -28,7 +28,7 @@
 int osdep_xenforeignmemory_open(xenforeignmemory_handle *fmem)
 {
     int flags, saved_errno;
-    int fd = open("/kern/xen/privcmd", O_RDWR);
+    int fd = open("/kern/xen/privcmd", O_RDWR|O_CLOEXEC);
 
     if ( fd == -1 )
     {
