$NetBSD: patch-scripts_Help_About_About.js,v 1.1 2016/08/30 10:56:04 plunky Exp $

add some system information to About window

--- scripts/Help/About/About.js.orig	2016-08-04 12:53:50.087339591 +0000
+++ scripts/Help/About/About.js
@@ -425,6 +425,16 @@ About.prototype.initAboutSystem = functi
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
