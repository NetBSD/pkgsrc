$NetBSD: patch-tools_qemu-xen_net_tap-bsd.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- tools/qemu-xen/net/tap-bsd.c.orig	2020-05-18 10:41:00.816005830 +0200
+++ tools/qemu-xen/net/tap-bsd.c	2020-05-18 15:02:30.497691415 +0200
@@ -40,7 +40,7 @@
 #include <sys/param.h>
 #endif
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 int tap_open(char *ifname, int ifname_size, int *vnet_hdr,
              int vnet_hdr_required, int mq_required, Error **errp)
 {
@@ -112,7 +112,7 @@
     return fd;
 }
 
-#else /* __FreeBSD__ */
+#else /* __FreeBSD__ || __NetBSD__ */
 
 #define PATH_NET_TAP "/dev/tap"
 
@@ -137,6 +137,7 @@
     }
 
     if (ifname[0] != '\0') {
+#ifdef SIOCSIFNAME
         /* User requested the interface to have a specific name */
         s = socket(AF_LOCAL, SOCK_DGRAM, 0);
         if (s < 0) {
@@ -153,10 +154,12 @@
             close(fd);
             return -1;
         }
+#else
+        pstrcpy(ifname, ifname_size, ifr.ifr_name);
+#endif
     } else {
         pstrcpy(ifname, ifname_size, ifr.ifr_name);
     }
-
     return fd;
 }
 
