$NetBSD: patch-jdk_src_solaris_classes_sun_net_PortConfig.java,v 1.2 2014/05/02 10:48:13 ryoon Exp $

--- jdk/src/solaris/classes/sun/net/PortConfig.java.orig	2014-05-01 13:11:40.000000000 +0000
+++ jdk/src/solaris/classes/sun/net/PortConfig.java
@@ -52,7 +52,7 @@ public final class PortConfig {
                     } else if (os.startsWith("SunOS")) {
                         defaultLower = 32768;
                         defaultUpper = 65535;
-                    } else if (os.contains("OS X") || os.endsWith("BSD")) {
+                    } else if (os.contains("OS X") || os.endsWith("BSD") || os.contains("DragonFly")) {
                         defaultLower = 49152;
                         defaultUpper = 65535;
                     } else {
