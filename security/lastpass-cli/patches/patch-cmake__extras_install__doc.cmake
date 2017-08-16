$NetBSD: patch-cmake__extras_install__doc.cmake,v 1.1 2017/08/16 15:18:24 jperkin Exp $

Remove incompatible -v flag for bsdinstall.

--- cmake_extras/install_doc.cmake.orig	2017-06-28 12:50:49.000000000 +0000
+++ cmake_extras/install_doc.cmake
@@ -1,2 +1,2 @@
-execute_process(COMMAND install -v -d $ENV{DESTDIR}${MANDIR}/man1)
-execute_process(COMMAND install -m 0644 -v ${CMAKE_BINARY_DIR}/lpass.1 $ENV{DESTDIR}${MANDIR}/man1/lpass.1)
+execute_process(COMMAND install -d $ENV{DESTDIR}${MANDIR}/man1)
+execute_process(COMMAND install -m 0644 ${CMAKE_BINARY_DIR}/lpass.1 $ENV{DESTDIR}${MANDIR}/man1/lpass.1)
