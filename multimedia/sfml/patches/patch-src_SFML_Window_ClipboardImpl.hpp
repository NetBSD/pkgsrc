$NetBSD: patch-src_SFML_Window_ClipboardImpl.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/ClipboardImpl.hpp.orig	2018-10-15 19:41:39.000000000 +0000
+++ src/SFML/Window/ClipboardImpl.hpp
@@ -32,7 +32,7 @@
 
 #if defined(SFML_SYSTEM_WINDOWS)
     #include <SFML/Window/Win32/ClipboardImpl.hpp>
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_OPENBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD) || defined(SFML_SYSTEM_OPENBSD)
     #include <SFML/Window/Unix/ClipboardImpl.hpp>
 #elif defined(SFML_SYSTEM_MACOS)
     #include <SFML/Window/OSX/ClipboardImpl.hpp>
