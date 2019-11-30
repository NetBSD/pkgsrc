$NetBSD: patch-cmake_modules_FindLibVNCServer.cmake,v 1.1 2019/11/30 19:28:45 markd Exp $

Skip test - pkgsrc supplied version works.

--- cmake/modules/FindLibVNCServer.cmake.orig	2019-11-01 21:57:11.000000000 +0000
+++ cmake/modules/FindLibVNCServer.cmake
@@ -33,7 +33,8 @@ int main()
     return 0;
 }
     ")
-    CHECK_CXX_SOURCE_COMPILES("${_TEST_SOURCE_CODE}" LIBVNCSERVER_FOUND)
+#    CHECK_CXX_SOURCE_COMPILES("${_TEST_SOURCE_CODE}" LIBVNCSERVER_FOUND)
+   SET(LIBVNCSERVER_FOUND TRUE)
 ENDIF (LIBVNCSERVER_INCLUDE_DIR AND LIBVNCSERVER_LIBRARIES)
 
 IF (LIBVNCSERVER_FOUND)
