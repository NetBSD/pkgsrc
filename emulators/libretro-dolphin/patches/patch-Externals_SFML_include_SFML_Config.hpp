$NetBSD: patch-Externals_SFML_include_SFML_Config.hpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Externals/SFML/include/SFML/Config.hpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Externals/SFML/include/SFML/Config.hpp
@@ -59,6 +59,11 @@
     // FreeBSD
     #define SFML_SYSTEM_FREEBSD
 
+#elif defined(__NetBSD__)
+
+    // NetBSD
+    #define SFML_SYSTEM_NETBSD
+
 #else
 
     // Unsupported system
