$NetBSD: patch-hotspot_agent_src_share_classes_sun_jvm_hotspot_utilities_PlatformInfo.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- hotspot/agent/src/share/classes/sun/jvm/hotspot/utilities/PlatformInfo.java.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/agent/src/share/classes/sun/jvm/hotspot/utilities/PlatformInfo.java
@@ -45,6 +45,8 @@ public class PlatformInfo {
       return "bsd";
     } else if (os.contains("Darwin") || os.contains("OS X")) {
       return "darwin";
+    } else if (os.equals("DragonFlyBSD")) {
+      return "bsd";
     } else if (os.startsWith("Windows")) {
       return "win32";
     } else {
