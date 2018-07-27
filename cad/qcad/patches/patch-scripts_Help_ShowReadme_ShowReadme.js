$NetBSD: patch-scripts_Help_ShowReadme_ShowReadme.js,v 1.2 2018/07/27 14:12:41 plunky Exp $

fix path to file

--- scripts/Help/ShowReadme/ShowReadme.js.orig	2018-07-10 13:17:39.000000000 +0000
+++ scripts/Help/ShowReadme/ShowReadme.js
@@ -19,7 +19,7 @@
 
 include("scripts/Help/Help.js");
 
-ShowReadme.readmeFile = "readme.txt";
+ShowReadme.readmeFile = "@PREFIX@/share/qcad/readme.txt";
 
 function ShowReadme(guiAction) {
     Help.call(this, guiAction);
