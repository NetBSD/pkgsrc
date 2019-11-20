$NetBSD: patch-openbabel-3.pc.cmake,v 1.1 2019/11/20 18:07:55 kamil Exp $

--- openbabel-3.pc.cmake.orig	2019-10-07 16:39:17.000000000 +0000
+++ openbabel-3.pc.cmake
@@ -2,7 +2,7 @@ prefix=@CMAKE_INSTALL_PREFIX@
 exec_prefix=${prefix}
 libdir=${exec_prefix}/@LIB_INSTALL_DIR@
 includedir=${prefix}/include
-pkgincludedir=${includedir}/openbabel-2.0
+pkgincludedir=${includedir}/openbabel3/
 
 Name: Open Babel library
 Description: libopenbabel
