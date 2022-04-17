$NetBSD: patch-cmake_readline.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

* If devel/editline is installed and use base libedit, cmake
  readline.h detection fails. Disable mis-detection of
  /usr/pkg/editline/readline.h.

--- cmake/readline.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ cmake/readline.cmake
@@ -108,10 +108,10 @@ ENDMACRO()
 
 MACRO (FIND_SYSTEM_EDITLINE)
   FIND_PATH(FOUND_EDITLINE_READLINE
-    NAMES editline/readline.h
+    NAMES readline/readline.h
   )
   IF(FOUND_EDITLINE_READLINE)
-    SET(EDITLINE_INCLUDE_DIR "${FOUND_EDITLINE_READLINE}/editline")
+    SET(EDITLINE_INCLUDE_DIR "${FOUND_EDITLINE_READLINE}/readline")
   ELSE()
     # Different path on FreeBSD
     FIND_PATH(FOUND_EDIT_READLINE_READLINE
