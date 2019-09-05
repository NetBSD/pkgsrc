$NetBSD: patch-scripts_Help_About_About.js,v 1.2 2019/09/05 13:39:10 nia Exp $

add some system information to About window

--- scripts/Help/About/About.js.orig	2019-07-18 15:47:56.000000000 +0000
+++ scripts/Help/About/About.js
@@ -451,6 +451,16 @@ About.prototype.initAboutSystem = functi
     if (RS.getSystemId()==="linux") {
         text += "Linux";
     }
+    if (RS.getSystemId()==="netbsd") {
+        text += "NetBSD";
+    }
+    if (RS.getSystemId()==="freebsd") {
+        text += "FreeBSD";
+    }
+    if (RS.getSystemId()==="solaris") {
+        text += "Solaris";
+    }
+    text += " [via pkgsrc]";
     text += "\nOS version: " + RSettings.getOSVersion();
 
     text += "\n";
