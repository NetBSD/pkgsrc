$NetBSD: patch-src_main.cpp,v 1.1 2024/08/18 05:16:09 wiz Exp $

Fix hardcoded path

--- src/main.cpp.orig	2024-05-10 15:50:35.000000000 +0000
+++ src/main.cpp
@@ -301,8 +301,8 @@
     // Only Windows 10 has tar. Older windows versions not supported.
     zipToolPath = "tar";
 #else
-    zipToolPath = "/usr/bin/zip";
-    unzipToolPath = "/usr/bin/unzip";
+    zipToolPath = "@PREFIX@/bin/zip";
+    unzipToolPath = "@PREFIX@/bin/unzip";
 #endif
     iconPath = vymBaseDir.path() + "/icons/";
     flagsPath = vymBaseDir.path() + "/flags/";
