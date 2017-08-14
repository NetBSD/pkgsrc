$NetBSD: patch-jdk_src_solaris_classes_sun_net_PortConfig.java,v 1.3 2017/08/14 00:02:16 ryoon Exp $

--- jdk/src/solaris/classes/sun/net/PortConfig.java.orig	2017-08-13 05:55:21.000000000 +0000
+++ jdk/src/solaris/classes/sun/net/PortConfig.java
@@ -59,7 +59,7 @@ public final class PortConfig {
                     } else if (os.startsWith("AIX")) {
                         defaultLower = 32768;
                         defaultUpper = 65535;
-                    } else if (os.contains("OS X") || os.endsWith("BSD")) {
+                    } else if (os.contains("OS X") || os.endsWith("BSD") || os.contains("DragonFly")) {
                         defaultLower = 49152;
                         defaultUpper = 65535;
                     } else {
