$NetBSD: patch-jdk_src_solaris_native_java_net_NetworkInterface.c,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Zones support.

--- jdk/src/solaris/native/java/net/NetworkInterface.c.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/src/solaris/native/java/net/NetworkInterface.c
@@ -43,6 +43,7 @@
 #include <fcntl.h>
 #include <stropts.h>
 #include <sys/sockio.h>
+#include <zone.h>
 #endif
 
 #ifdef __linux__
@@ -1525,7 +1526,8 @@ static short getSubnet(JNIEnv *env, int
 
 
 
-#define DEV_PREFIX  "/dev/"
+#define NET_DEV_PREFIX  "/dev/"
+#define ZONE_NET_DEV_PREFIX  "/dev/net/"
 
 /**
  * Solaris specific DLPI code to get hardware address from a device.
@@ -1542,11 +1544,18 @@ static int getMacFromDevice(JNIEnv *env,
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
