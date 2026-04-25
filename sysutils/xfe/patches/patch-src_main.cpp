$NetBSD: patch-src_main.cpp,v 1.3 2026/04/25 10:00:26 vins Exp $

Allow build on any platform with an unknown packagin system.

--- src/main.cpp.orig	2026-01-17 16:07:41.000000000 +0000
+++ src/main.cpp
@@ -388,12 +388,10 @@ int main(int argc, char* argv[])
     textdomain(PACKAGE);
 #endif
 
-#if defined(__FreeBSD__)
+#if !defined(__linux__)
     FXuint pkg_format;
     pkg_format = OTHER_PKG;
-#endif
-
-#if defined(linux)
+#else
     // For package query on Linux systems, try to guess if the default package format is deb or rpm:
     //   - if dpkg exists then the system uses deb packages
     //   - else if rpm exists, then the system uses rpm packages
