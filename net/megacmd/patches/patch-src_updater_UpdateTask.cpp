$NetBSD: patch-src_updater_UpdateTask.cpp,v 1.1 2026/01/08 17:52:20 kikadf Exp $

* Fix ctype(3) tolower usage

--- src/updater/UpdateTask.cpp.orig	2026-01-04 16:27:16.088641735 +0100
+++ src/updater/UpdateTask.cpp
@@ -589,7 +589,8 @@ string getDistro()
     {
         distro = distro.substr(0, 20);
     }
-    transform(distro.begin(), distro.end(), distro.begin(), ::tolower);
+    transform(distro.begin(), distro.end(), distro.begin(),
+              [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
     return distro;
 }
 
@@ -605,7 +606,8 @@ string getDistroVersion()
     {
         version = version.substr(0, 10);
     }
-    transform(version.begin(), version.end(), version.begin(), ::tolower);
+    transform(version.begin(), version.end(), version.begin(),
+              [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
     return version;
 }
 #endif
