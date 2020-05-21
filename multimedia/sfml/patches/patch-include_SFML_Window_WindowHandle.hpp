$NetBSD: patch-include_SFML_Window_WindowHandle.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- include/SFML/Window/WindowHandle.hpp.orig	2018-10-15 19:41:39.000000000 +0000
+++ include/SFML/Window/WindowHandle.hpp
@@ -42,7 +42,7 @@ namespace sf
     // Window handle is HWND (HWND__*) on Windows
     typedef HWND__* WindowHandle;
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_OPENBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD) || defined(SFML_SYSTEM_OPENBSD)
 
     // Window handle is Window (unsigned long) on Unix - X11
     typedef unsigned long WindowHandle;
