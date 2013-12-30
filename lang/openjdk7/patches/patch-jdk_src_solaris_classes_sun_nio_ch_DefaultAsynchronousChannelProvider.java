$NetBSD: patch-jdk_src_solaris_classes_sun_nio_ch_DefaultAsynchronousChannelProvider.java,v 1.1 2013/12/30 07:02:28 ryoon Exp $

* Fix apache-tomcat7's error, "java.lang.InternalError: platform not recognized"
  patch is from http://www.freebsd.org/cgi/query-pr.cgi?pr=183389

--- jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java.orig	2013-06-25 14:32:43.000000000 +0000
+++ jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java
@@ -50,7 +50,7 @@ public class DefaultAsynchronousChannelP
             return new SolarisAsynchronousChannelProvider();
         if (osname.equals("Linux"))
             return new LinuxAsynchronousChannelProvider();
-        if (osname.contains("OS X"))
+        if (osname.contains("OS X") || osname.contains("DragonFly") || osname.contains("FreeBSD") || osname.contains("NetBSD") || osname.contains("OpenBSD"))
             return new BsdAsynchronousChannelProvider();
         throw new InternalError("platform not recognized");
     }
