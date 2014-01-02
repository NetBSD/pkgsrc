$NetBSD: patch-jdk_src_solaris_native_java_net_NetworkInterface.c,v 1.2 2014/01/02 01:16:35 ryoon Exp $

Zones support.

--- jdk/src/solaris/native/java/net/NetworkInterface.c.orig	2014-01-01 05:53:43.000000000 +0000
+++ jdk/src/solaris/native/java/net/NetworkInterface.c
@@ -43,6 +43,7 @@
 #include <fcntl.h>
 #include <stropts.h>
 #include <sys/sockio.h>
+#include <zone.h>
 #endif
 
 #ifdef __linux__
@@ -60,13 +61,11 @@
 #include <sys/param.h>
 #include <sys/ioctl.h>
 #include <sys/sockio.h>
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 #include <net/ethernet.h>
 #include <net/if_var.h>
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 #include <netinet/if_ether.h>
-#elif defined(__NetBSD__)
-#include <net/if_ether.h>
 #endif
 #include <net/if_dl.h>
 #include <netinet/in_var.h>
@@ -1528,7 +1527,8 @@ static short getSubnet(JNIEnv *env, int 
 
 
 
-#define DEV_PREFIX  "/dev/"
+#define NET_DEV_PREFIX  "/dev/"
+#define ZONE_NET_DEV_PREFIX  "/dev/net/"
 
 /**
  * Solaris specific DLPI code to get hardware address from a device.
@@ -1545,11 +1545,18 @@ static int getMacFromDevice(JNIEnv *env,
     int flags = 0;
 
    /**
-    * Device is in /dev
+    * Device is in /dev in global zone / standalone
     * e.g.: /dev/bge0
+    * Device is in /dev/net in a zone
+    * e.g.: /dev/net/net0
     */
-    strcpy(style1dev, DEV_PREFIX);
+    if (getzoneid()==(zoneid_t)GLOBAL_ZONEID) {
+        strcpy(style1dev, NET_DEV_PREFIX);
+    } else {
+        strcpy(style1dev, ZONE_NET_DEV_PREFIX);
+    }
     strcat(style1dev, ifname);
+
     if ((fd = open(style1dev, O_RDWR)) < 0) {
         /*
          * Can't open it. We probably are missing the privilege.
