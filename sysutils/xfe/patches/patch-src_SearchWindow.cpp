$NetBSD: patch-src_SearchWindow.cpp,v 1.1 2026/04/25 10:00:26 vins Exp $

Replace gnuisms.

--- src/SearchWindow.cpp.orig	2026-04-25 09:08:13.086104379 +0000
+++ src/SearchWindow.cpp
@@ -800,7 +800,7 @@ long SearchWindow::onCmdStart(FXObject*,
     // Don't follow symlinks
     if (linkbtn->getCheck())
     {
-        searchcommand = "find -P " + xf_quote(wheredir->getText());
+        searchcommand = "find " + xf_quote(wheredir->getText());
     }
     else
     {
@@ -906,7 +906,7 @@ long SearchWindow::onCmdStart(FXObject*,
     // Hidden files
     if (!findhidden->getCheck())
     {
-        searchcommand += " \\( ! -regex '.*/\\..*' \\)";
+        searchcommand += " ! -path .";
     }
 
     // Without grep command
