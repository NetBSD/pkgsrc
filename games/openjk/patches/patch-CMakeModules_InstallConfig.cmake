$NetBSD: patch-CMakeModules_InstallConfig.cmake,v 1.1 2019/11/03 12:12:56 nia Exp $

Install to share/.

--- CMakeModules/InstallConfig.cmake.orig	2019-10-30 05:48:12.000000000 +0000
+++ CMakeModules/InstallConfig.cmake
@@ -17,8 +17,8 @@
 #============================================================================
 
 # Subdirectories to package JK2 and JKA into
-set(JKAInstallDir "JediAcademy")
-set(JK2InstallDir "JediOutcast")
+set(JKAInstallDir "share/JediAcademy")
+set(JK2InstallDir "share/JediOutcast")
 
 # Install components
 set(JKAMPCoreComponent "JKAMPCore")
