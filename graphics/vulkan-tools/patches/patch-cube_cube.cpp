$NetBSD: patch-cube_cube.cpp,v 1.3 2026/06/22 08:17:58 kikadf Exp $

Allow building on NetBSD.

--- cube/cube.cpp.orig	2026-06-22 09:43:59.139544311 +0200
+++ cube/cube.cpp
@@ -4144,7 +4144,7 @@ int WINAPI WinMain(HINSTANCE hInstance, 
 }
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || \
-    defined(__Fuchsia__)
+    defined(__Fuchsia__) || defined(__NetBSD__)
 
 template <WsiPlatform WSI_PLATFORM>
 void Demo::execute() {
