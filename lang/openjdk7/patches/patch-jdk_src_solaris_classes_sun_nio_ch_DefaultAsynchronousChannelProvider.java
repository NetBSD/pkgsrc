$NetBSD: patch-jdk_src_solaris_classes_sun_nio_ch_DefaultAsynchronousChannelProvider.java,v 1.3 2017/08/14 00:02:16 ryoon Exp $

* Fix apache-tomcat7's error, "java.lang.InternalError: platform not recognized"
  patch is from http://www.freebsd.org/cgi/query-pr.cgi?pr=183389

--- jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java.orig	2017-08-13 05:55:21.000000000 +0000
+++ jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java
@@ -50,7 +50,7 @@ public class DefaultAsynchronousChannelP
             return new SolarisAsynchronousChannelProvider();
         if (osname.equals("Linux"))
             return new LinuxAsynchronousChannelProvider();
-        if (osname.contains("OS X") || osname.endsWith("BSD"))
+        if (osname.contains("OS X") || osname.endsWith("BSD") || osname.contains("DragonFly"))
             return new BsdAsynchronousChannelProvider();
         if (osname.equals("AIX"))
             return new AixAsynchronousChannelProvider();
