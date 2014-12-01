$NetBSD: patch-cmake_readline.cmake,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

* If devel/editline is installed and use base libedit, cmake
  readline.h detection fails. Disable mis-detection of
  /usr/pkg/editline/readline.h.

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
