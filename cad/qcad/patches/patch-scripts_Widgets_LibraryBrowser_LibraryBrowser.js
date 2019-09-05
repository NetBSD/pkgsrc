$NetBSD: patch-scripts_Widgets_LibraryBrowser_LibraryBrowser.js,v 1.2 2019/09/05 13:39:10 nia Exp $

fix path to libraries

--- scripts/Widgets/LibraryBrowser/LibraryBrowser.js.orig	2019-07-18 15:47:56.000000000 +0000
+++ scripts/Widgets/LibraryBrowser/LibraryBrowser.js
@@ -174,12 +174,12 @@ LibraryBrowser.getSourceList = function(
     var libs;
 
     // no configuration: add all libraries available in libraries subdir:
-    librariesDir = new QDir("libraries");
+    librariesDir = new QDir("@PREFIX@/share/qcad/libraries");
     libs = librariesDir.entryList([], filters, sortFlags);
     for (i=0; i<libs.length; i++) {
         // always add default library if available:
         if (libs[i]==="default" || noSourcesConfigured) {
-            sourceList.push(QDir.fromNativeSeparators(new QDir("libraries/%1".arg(libs[i])).absolutePath()));
+            sourceList.push(QDir.fromNativeSeparators(new QDir("%1/%2".arg(librariesDir.absolutePath()).arg(libs[i])).absolutePath()));
         }
     }
 
