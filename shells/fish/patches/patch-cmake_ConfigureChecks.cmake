$NetBSD: patch-cmake_ConfigureChecks.cmake,v 1.1 2020/02/18 22:00:49 maya Exp $

put #define TPARM_VARARGS to get the varargs tparm.
(For netbsd curses)

Simply variadic tparm logic, and make sure it doesn't consider the
"solaris (curses) kludge" necessary on netbsd.

--- cmake/ConfigureChecks.cmake.orig	2020-02-12 14:04:07.000000000 +0000
+++ cmake/ConfigureChecks.cmake
@@ -158,25 +158,26 @@ int main () {
 "
   TPARM_TAKES_VARARGS
 )
-IF(NOT TPARM_TAKES_VARARGS)
-  CHECK_CXX_SOURCE_COMPILES("
-${TPARM_INCLUDES}
+
+CHECK_CXX_SOURCE_COMPILES("
 #define TPARM_VARARGS
+${TPARM_INCLUDES}
 
 int main () {
   tparm( \"\" );
 }
 "
-    TPARM_TAKES_VARARGS_WITH_VARARGS
-    )
-  IF(NOT TPARM_TAKES_VARARGS)
-    SET(TPARM_SOLARIS_KLUDGE 1)
-  ELSE()
-    SET(TPARM_VARARGS 1)
-  ENDIF()
-ENDIF()
+  TPARM_TAKES_VARARGS_WITH_VARARGS
+)
 CMAKE_POP_CHECK_STATE()
 
+IF(TPARM_TAKES_VARARGS)
+ELSEIF(TPARM_TAKES_VARARGS_WITH_VARARGS)
+  SET(TPARM_VARARGS 1)
+ELSE()
+  SET(TPARM_SOLARIS_KLUDGE 1)
+ENDIF()
+
 # Work around the fact that cmake does not propagate the language standard flag into
 # the CHECK_CXX_SOURCE_COMPILES function. See CMake issue #16456.
 # Ensure we do this after the FIND_PACKAGE calls which use C, and will error on a C++
