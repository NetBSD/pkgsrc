$NetBSD: patch-cmake_readline.cmake,v 1.2 2020/05/07 05:31:53 adam Exp $

Fix for devel/editline.

--- cmake/readline.cmake.orig	2020-03-23 17:35:17.000000000 +0000
+++ cmake/readline.cmake
@@ -103,10 +103,10 @@ ENDMACRO()
 
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
