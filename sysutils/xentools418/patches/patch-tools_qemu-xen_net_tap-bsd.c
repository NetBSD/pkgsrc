$NetBSD: patch-tools_qemu-xen_net_tap-bsd.c,v 1.1 2023/11/21 11:37:03 bouyer Exp $

--- tools/qemu-xen/net/tap-bsd.c.orig	2023-08-16 11:43:53.000000000 +0200
+++ tools/qemu-xen/net/tap-bsd.c	2023-11-14 17:27:20.501570015 +0100
@@ -34,7 +34,7 @@
 #include <net/if_tap.h>
 #endif
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 int tap_open(char *ifname, int ifname_size, int *vnet_hdr,
              int vnet_hdr_required, int mq_required, Error **errp)
 {
@@ -102,7 +102,7 @@
     return fd;
 }
 
-#else /* __FreeBSD__ */
+#else /* !__FreeBSD__ && !__NetBSD__ */
 
 #define PATH_NET_TAP "/dev/tap"
 
@@ -127,6 +127,7 @@
     }
 
     if (ifname[0] != '\0') {
+#ifdef SIOCSIFNAME
         /* User requested the interface to have a specific name */
         s = socket(AF_LOCAL, SOCK_DGRAM, 0);
         if (s < 0) {
@@ -143,10 +144,12 @@
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
 
