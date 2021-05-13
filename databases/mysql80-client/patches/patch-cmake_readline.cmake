$NetBSD: patch-cmake_readline.cmake,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

Fix for pkgsrc editline.

--- cmake/readline.cmake.orig	2016-06-30 06:22:11.000000000 +0000
+++ cmake/readline.cmake
@@ -112,10 +112,10 @@ ENDMACRO()
 
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
