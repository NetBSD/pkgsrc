$NetBSD: patch-jdk_src_solaris_classes_sun_nio_ch_DefaultAsynchronousChannelProvider.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

* Fix apache-tomcat7's error, "java.lang.InternalError: platform not recognized"
  patch is from http://www.freebsd.org/cgi/query-pr.cgi?pr=183389

--- jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java
@@ -66,7 +66,7 @@ public class DefaultAsynchronousChannelP
             return createProvider("sun.nio.ch.SolarisAsynchronousChannelProvider");
         if (osname.equals("Linux"))
             return createProvider("sun.nio.ch.LinuxAsynchronousChannelProvider");
-        if (osname.endsWith("BSD") || osname.contains("OS X"))
+        if (osname.endsWith("BSD") || osname.contains("OS X") || osname.contains("DragonFly"))
             return createProvider("sun.nio.ch.BsdAsynchronousChannelProvider");
         if (osname.equals("AIX"))
             return createProvider("sun.nio.ch.AixAsynchronousChannelProvider");
