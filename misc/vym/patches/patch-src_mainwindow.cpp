$NetBSD: patch-src_mainwindow.cpp,v 1.1 2024/08/18 05:16:09 wiz Exp $

Fix hardcoded path

--- src/mainwindow.cpp.orig	2024-05-10 15:50:35.000000000 +0000
+++ src/mainwindow.cpp
@@ -7031,6 +7031,7 @@
     searchList << "doc"; // relative path for easy testing in tarball
     searchList << "/usr/share/doc/vym";      // Debian
     searchList << "/usr/share/doc/packages"; // Knoppix
+    searchList << "@PREFIX@/share/doc/vym";
 
     bool found = false;
     QFile docfile;
