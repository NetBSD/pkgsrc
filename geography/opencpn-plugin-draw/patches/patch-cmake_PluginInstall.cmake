$NetBSD: patch-cmake_PluginInstall.cmake,v 1.1 2016/05/21 10:50:41 bouyer Exp $

--- cmake/PluginInstall.cmake.orig	2016-04-13 08:28:11.000000000 +0200
+++ cmake/PluginInstall.cmake	2016-05-21 12:20:58.903393680 +0200
@@ -85,7 +85,6 @@
     #    SET (PACKAGE_DEPS  "wxGTK mesa-libGLU mesa-libGL gettext zlib bzip2 portaudio")
     IF (CMAKE_SIZEOF_VOID_P MATCHES "8")
       SET (ARCH "x86_64")
-      SET (LIB_INSTALL_DIR "lib64")
     ELSE (CMAKE_SIZEOF_VOID_P MATCHES "8")
       SET (ARCH "i386")
       SET (LIB_INSTALL_DIR "lib")
@@ -96,7 +95,6 @@
     #    SET (PACKAGE_DEPS  "libwx_baseu-2_8-0-wxcontainer MesaGLw libbz2-1 portaudio")
     IF (CMAKE_SIZEOF_VOID_P MATCHES "8")
       SET (ARCH "x86_64")
-      SET (LIB_INSTALL_DIR "lib64")
     ELSE (CMAKE_SIZEOF_VOID_P MATCHES "8")
       SET (ARCH "i386")
       SET (LIB_INSTALL_DIR "lib")
