$NetBSD: patch-cmake_Config.cmake,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- cmake/Config.cmake.orig	2018-10-15 19:41:39.000000000 +0000
+++ cmake/Config.cmake
@@ -31,6 +31,10 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "^k?Fre
     set(SFML_OS_FREEBSD 1)
     # don't use the OpenGL ES implementation on FreeBSD
     set(OPENGL_ES 0)
+elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+    set(SFML_OS_NETBSD 1)
+    # XXX we want to use OPENGL_ES for some NetBSD, but which?
+    set(OPENGL_ES 0)
 elseif(CMAKE_SYSTEM_NAME MATCHES "^OpenBSD$")
     set(SFML_OS_OPENBSD 1)
     # don't use the OpenGL ES implementation on OpenBSD
@@ -77,6 +81,10 @@ if(SFML_OS_FREEBSD OR SFML_OS_OPENBSD)
     set(SFML_PKGCONFIG_DIR "/libdata/pkgconfig")
 endif()
 
+if(SFML_OS_NETBSD)
+    set(SFML_PKGCONFIG_DIR "/lib/pkgconfig")
+endif()
+
 # detect the compiler and its version
 # Note: on some platforms (OS X), CMAKE_COMPILER_IS_GNUCXX is true
 # even when CLANG is used, therefore the Clang test is done first
