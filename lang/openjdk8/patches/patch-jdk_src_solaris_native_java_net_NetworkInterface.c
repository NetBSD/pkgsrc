$NetBSD: patch-jdk_src_solaris_native_java_net_NetworkInterface.c,v 1.3.10.1 2017/12/20 16:54:59 spz Exp $

Zones support.

--- jdk/src/solaris/native/java/net/NetworkInterface.c.orig	2017-11-28 00:13:32.000000000 +0000
+++ jdk/src/solaris/native/java/net/NetworkInterface.c
@@ -39,6 +39,7 @@
 #include <fcntl.h>
 #include <stropts.h>
 #include <sys/sockio.h>
+#include <zone.h>
 #endif
 
 #if defined(__linux__)
@@ -58,14 +59,12 @@
 #include <sys/param.h>
 #include <sys/ioctl.h>
 #include <sys/sockio.h>
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <net/ethernet.h>
 #include <net/if_var.h>
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 #include <netinet/if_ether.h>
 #include <netinet6/in6_var.h>
-#elif defined(__NetBSD__)
-#include <net/if_ether.h>
 #endif
 #include <net/if_dl.h>
 #include <netinet/in_var.h>
@@ -82,7 +81,8 @@
     #ifndef SIOCGLIFHWADDR
         #define SIOCGLIFHWADDR _IOWR('i', 192, struct lifreq)
     #endif
-    #define DEV_PREFIX "/dev/"
+    #define NET_DEV_PREFIX "/dev/"
+    #define ZONE_NET_DEV_PREFIX    "/dev/net/"
 #endif
 
 #ifdef LIFNAMSIZ
@@ -1843,9 +1843,18 @@ static int getMacFromDevice
     char buf[128];
     int flags = 0;
 
-    // Device is in /dev.  e.g.: /dev/bge0
-    strcpy(style1dev, DEV_PREFIX);
+   /*
+    * Device is in /dev in global zone / standalone
+    * Device is in /dev/net in a zone
+    * e.g.: /dev/net/net0
+    */
+    if (getzoneid()==(zoneid_t)GLOBAL_ZONEID) {
+        strcpy(style1dev, NET_DEV_PREFIX);
+    } else {
+        strcpy(style1dev, ZONE_NET_DEV_PREFIX);
+    }
     strcat(style1dev, ifname);
+
     if ((fd = open(style1dev, O_RDWR)) < 0) {
         // Can't open it. We probably are missing the privilege.
         // We'll have to try something else
