$NetBSD: patch-src_SFML_Window_JoystickImpl.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/JoystickImpl.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/JoystickImpl.hpp
@@ -86,7 +86,7 @@ struct JoystickState
 
     #include <SFML/Window/Unix/JoystickImpl.hpp>
 
-#elif defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_FREEBSD) || defined (SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/FreeBSD/JoystickImpl.hpp>
 
