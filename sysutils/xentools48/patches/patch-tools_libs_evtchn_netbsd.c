$NetBSD: patch-tools_libs_evtchn_netbsd.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libs/evtchn/netbsd.c.orig	2017-03-24 18:23:27.000000000 +0100
+++ tools/libs/evtchn/netbsd.c	2017-03-24 18:23:40.000000000 +0100
@@ -124,7 +124,7 @@
     int fd = xce->fd;
     evtchn_port_t port;
 
-    if ( read_exact(fd, (char *)&port, sizeof(port)) == -1 )
+    if ( read(fd, (char *)&port, sizeof(port)) == -1 )
         return -1;
 
     return port;
@@ -133,7 +133,7 @@
 int xenevtchn_unmask(xenevtchn_handle *xce, evtchn_port_t port)
 {
     int fd = xce->fd;
-    return write_exact(fd, (char *)&port, sizeof(port));
+    return write(fd, (char *)&port, sizeof(port));
 }
 
 /*
