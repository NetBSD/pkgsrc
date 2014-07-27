$NetBSD: patch-hotspot_agent_src_share_classes_sun_jvm_hotspot_utilities_PlatformInfo.java,v 1.1.2.2 2014/07/27 12:36:21 spz Exp $

--- hotspot/agent/src/share/classes/sun/jvm/hotspot/utilities/PlatformInfo.java.orig	2014-06-14 20:38:20.000000000 +0000
+++ hotspot/agent/src/share/classes/sun/jvm/hotspot/utilities/PlatformInfo.java
@@ -45,6 +45,8 @@ public class PlatformInfo {
       return "bsd";
     } else if (os.equals("Darwin") || os.contains("OS X")) {
       return "bsd";
+    } else if (os.equals("DragonFlyBSD")) {
+      return "bsd";
     } else if (os.startsWith("Windows")) {
       return "win32";
     } else {
