$NetBSD: patch-scripts_Help_ShowReadme_ShowReadme.js,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix path to file

--- scripts/Help/ShowReadme/ShowReadme.js.orig	2016-07-01 07:13:14.000000000 +0000
+++ scripts/Help/ShowReadme/ShowReadme.js
@@ -19,7 +19,7 @@

 include("../Help.js");

-ShowReadme.readmeFile = "readme.txt";
+ShowReadme.readmeFile = "@PREFIX@/share/qcad/readme.txt";

 function ShowReadme(guiAction) {
     Help.call(this, guiAction);
