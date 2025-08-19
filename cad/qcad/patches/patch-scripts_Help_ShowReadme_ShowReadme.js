$NetBSD: patch-scripts_Help_ShowReadme_ShowReadme.js,v 1.3 2025/08/19 12:52:17 plunky Exp $

fix path to file

--- scripts/Help/ShowReadme/ShowReadme.js.orig	2025-06-10 07:10:41.000000000 +0000
+++ scripts/Help/ShowReadme/ShowReadme.js
@@ -19,7 +19,7 @@
 
 include("scripts/Help/Help.js");
 
-ShowReadme.readmeFile = "readme.txt";
+ShowReadme.readmeFile = "@PREFIX@/share/qcad/readme.txt";
 
 function ShowReadme(guiAction) {
     Help.call(this, guiAction);
