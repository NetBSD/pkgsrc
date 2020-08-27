$NetBSD: patch-tools_libs_evtchn_netbsd.c,v 1.2 2020/08/27 08:22:33 bouyer Exp $

--- tools/libs/evtchn/netbsd.c.orig	2020-05-14 14:19:32.000000000 +0200
+++ tools/libs/evtchn/netbsd.c	2020-05-27 14:07:41.348188034 +0200
@@ -25,10 +25,10 @@
 
 #include <sys/ioctl.h>
 
-#include <xen/sys/evtchn.h>
-
 #include "private.h"
 
+#include <xen/xenio3.h>
+
 #define EVTCHN_DEV_NAME  "/dev/xenevt"
 
 int osdep_evtchn_open(xenevtchn_handle *xce)
@@ -131,7 +131,7 @@
     int fd = xce->fd;
     evtchn_port_t port;
 
-    if ( read_exact(fd, (char *)&port, sizeof(port)) == -1 )
+    if ( read(fd, (char *)&port, sizeof(port)) == -1 )
         return -1;
 
     return port;
@@ -140,7 +140,7 @@
 int xenevtchn_unmask(xenevtchn_handle *xce, evtchn_port_t port)
 {
     int fd = xce->fd;
-    return write_exact(fd, (char *)&port, sizeof(port));
+    return write(fd, (char *)&port, sizeof(port));
 }
 
 /*
