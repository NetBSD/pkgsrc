$NetBSD: patch-cmake_readline.cmake,v 1.3.8.1 2016/10/22 16:18:27 bsiegert Exp $

Fix for pkgsrc editline.

--- cmake/readline.cmake.orig	2016-08-26 11:22:35.000000000 +0000
+++ cmake/readline.cmake
@@ -131,10 +131,10 @@ ENDMACRO()
 
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
