$NetBSD: patch-jdk_src_solaris_classes_sun_nio_ch_DefaultAsynchronousChannelProvider.java,v 1.2 2014/05/02 10:48:13 ryoon Exp $

* Fix apache-tomcat7's error, "java.lang.InternalError: platform not recognized"
  patch is from http://www.freebsd.org/cgi/query-pr.cgi?pr=183389

--- jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java.orig	2014-05-01 13:11:40.000000000 +0000
+++ jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java
@@ -50,7 +50,7 @@ public class DefaultAsynchronousChannelP
             return new SolarisAsynchronousChannelProvider();
         if (osname.equals("Linux"))
             return new LinuxAsynchronousChannelProvider();
-        if (osname.contains("OS X") || osname.endsWith("BSD"))
+        if (osname.contains("OS X") || osname.endsWith("BSD") || osname.contains("DragonFly"))
             return new BsdAsynchronousChannelProvider();
         throw new InternalError("platform not recognized");
     }
