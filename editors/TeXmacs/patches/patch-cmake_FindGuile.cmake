$NetBSD: patch-cmake_FindGuile.cmake,v 1.1 2019/10/28 15:10:00 kamil Exp $

Hack to set libguile library as find_library() does not work.

--- cmake/FindGuile.cmake.orig	2019-07-26 14:44:40.000000000 +0000
+++ cmake/FindGuile.cmake
@@ -64,7 +64,8 @@ IF(GUILECONFIG_EXECUTABLE)
         ENDIF(NOT _guile_flag_library_${i}) 
       ENDIF (i)
     ENDFOREACH(i)       
-           
+
+    SET(_guile_libraries ${_guile_libraries} "@PREFIX@/guile/1.8/lib/libguile.so")
 
 
     SET(Guile_FOUND YES)
@@ -89,4 +90,3 @@ ELSE(GUILECONFIG_EXECUTABLE)
 
 
 ENDIF(GUILECONFIG_EXECUTABLE)
-
