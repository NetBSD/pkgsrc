$NetBSD: patch-jdk_src_solaris_classes_sun_net_PortConfig.java,v 1.1 2014/01/25 13:53:22 ryoon Exp $

--- jdk/src/solaris/classes/sun/net/PortConfig.java.orig	2014-01-25 07:34:09.000000000 +0000
+++ jdk/src/solaris/classes/sun/net/PortConfig.java
@@ -55,6 +55,18 @@ public final class PortConfig {
                     } else if (os.contains("OS X")) {
                         defaultLower = 49152;
                         defaultUpper = 65535;
+                    } else if (os.startsWith("DragonFly")) {
+                        defaultLower = 32768;
+                        defaultUpper = 65535;
+                    } else if (os.startsWith("FreeBSD")) {
+                        defaultLower = 32768;
+                        defaultUpper = 65535;
+                    } else if (os.startsWith("NetBSD")) {
+                        defaultLower = 32768;
+                        defaultUpper = 65535;
+                    } else if (os.startsWith("OpenBSD")) {
+                        defaultLower = 32768;
+                        defaultUpper = 65535;
                     } else {
                         throw new InternalError(
                             "sun.net.PortConfig: unknown OS");
