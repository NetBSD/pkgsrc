$NetBSD: patch-cube_cube.cpp,v 1.1 2025/03/16 21:48:13 wiz Exp $

Allow building on NetBSD.

--- cube/cube.cpp.orig	2025-03-16 21:47:14.580034359 +0000
+++ cube/cube.cpp
@@ -3387,7 +3387,7 @@ int WINAPI WinMain(HINSTANCE hInstance, 
     return static_cast<int>(msg.wParam);
 }
 
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || defined(__NetBSD__)
 
 int main(int argc, char **argv) {
     Demo demo;
