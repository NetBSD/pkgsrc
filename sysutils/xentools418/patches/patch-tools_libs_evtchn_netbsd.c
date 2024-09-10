$NetBSD: patch-tools_libs_evtchn_netbsd.c,v 1.1 2024/09/10 12:40:15 bouyer Exp $
Set O_CLOEXEC if requested; avoid O_NONBLOCK (from libs/evtchn/freebsd.c)

--- tools/libs/evtchn/netbsd.c.orig	2024-04-12 16:52:51.230321519 +0200
+++ tools/libs/evtchn/netbsd.c	2024-04-12 16:55:02.402441409 +0200
@@ -33,8 +33,13 @@
 
 int osdep_evtchn_open(xenevtchn_handle *xce, unsigned int flags)
 {
-    int fd = open(EVTCHN_DEV_NAME, O_NONBLOCK|O_RDWR);
+    int open_flags = O_RDWR;
+    int fd;
 
+    if ( !(flags & XENEVTCHN_NO_CLOEXEC) )
+        open_flags |= O_CLOEXEC;
+
+    fd = open(EVTCHN_DEV_NAME, open_flags);
     if ( fd == -1 )
         return -1;
 
