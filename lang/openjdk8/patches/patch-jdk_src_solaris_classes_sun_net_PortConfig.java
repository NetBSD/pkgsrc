$NetBSD: patch-jdk_src_solaris_classes_sun_net_PortConfig.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- jdk/src/solaris/classes/sun/net/PortConfig.java.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/classes/sun/net/PortConfig.java
@@ -52,7 +52,7 @@ public final class PortConfig {
                     } else if (os.startsWith("SunOS")) {
                         defaultLower = 32768;
                         defaultUpper = 65535;
-                    } else if (os.endsWith("BSD") || os.contains("OS X")) {
+                    } else if (os.endsWith("BSD") || os.contains("OS X") || os.contains("DragonFly")) {
                         defaultLower = 49152;
                         defaultUpper = 65535;
                     } else if (os.startsWith("AIX")) {
