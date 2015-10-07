$NetBSD: patch-cmake_readline.cmake,v 1.3 2015/10/07 11:22:00 adam Exp $

* If devel/editline is installed and use base libedit, cmake
  readline.h detection fails. Disable mis-detection of
  /usr/pkg/include/editline/readline.h.

--- cmake/readline.cmake.orig	2013-05-21 15:18:39.000000000 +0000
+++ cmake/readline.cmake
@@ -130,9 +130,6 @@ MACRO (MYSQL_USE_BUNDLED_EDITLINE)
 ENDMACRO()
 
 MACRO (FIND_SYSTEM_EDITLINE)
-  FIND_PATH(FOUND_EDITLINE_READLINE
-    NAMES editline/readline.h
-  )
   IF(FOUND_EDITLINE_READLINE)
     SET(EDITLINE_INCLUDE_DIR "${FOUND_EDITLINE_READLINE}/editline")
   ELSE()
@@ -160,7 +157,7 @@ MACRO (FIND_SYSTEM_EDITLINE)
     SET(CMAKE_REQUIRED_LIBRARIES ${EDITLINE_LIBRARY})
     CHECK_CXX_SOURCE_COMPILES("
     #include <stdio.h>
-    #include <readline.h>
+    #include <readline/readline.h>
     int main(int argc, char **argv)
     {
        HIST_ENTRY entry;
@@ -170,7 +167,7 @@ MACRO (FIND_SYSTEM_EDITLINE)
 
     CHECK_CXX_SOURCE_COMPILES("
     #include <stdio.h>
-    #include <readline.h>
+    #include <readline/readline.h>
     int main(int argc, char **argv)
     {
       typedef int MYFunction(const char*, int);
