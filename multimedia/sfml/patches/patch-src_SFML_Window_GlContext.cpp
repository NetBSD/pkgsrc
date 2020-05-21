$NetBSD: patch-src_SFML_Window_GlContext.cpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/GlContext.cpp.orig	2018-10-15 19:41:39.000000000 +0000
+++ src/SFML/Window/GlContext.cpp
@@ -49,7 +49,7 @@
         #include <SFML/Window/Win32/WglContext.hpp>
         typedef sf::priv::WglContext ContextType;
 
-    #elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_OPENBSD)
+    #elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD) || defined(SFML_SYSTEM_OPENBSD)
 
         #include <SFML/Window/Unix/GlxContext.hpp>
         typedef sf::priv::GlxContext ContextType;
