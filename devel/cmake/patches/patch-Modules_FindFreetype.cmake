$NetBSD: patch-Modules_FindFreetype.cmake,v 1.1 2014/03/22 08:39:10 markd Exp $

fix check for freetype-2.5.1
Julian Ospald in http://www.cmake.org/Bug/view.php?id=14601

--- Modules/FindFreetype.cmake.orig	2013-11-05 19:07:22.000000000 +0000
+++ Modules/FindFreetype.cmake
@@ -70,6 +70,19 @@ find_path(FREETYPE_INCLUDE_DIR_freetype2
   PATH_SUFFIXES include/freetype2 include
 )
 
+if(NOT FREETYPE_INCLUDE_DIR_freetype2)
+  find_path(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h
+    HINTS
+      ENV FREETYPE_DIR
+    PATHS
+      /usr/X11R6
+      /usr/local/X11R6
+      /usr/local/X11
+      /usr/freeware
+    PATH_SUFFIXES include/freetype2 include
+  )
+endif()
+
 find_library(FREETYPE_LIBRARY
   NAMES freetype libfreetype freetype219
   HINTS
@@ -91,8 +104,14 @@ if(FREETYPE_INCLUDE_DIR_ft2build AND FRE
 endif()
 set(FREETYPE_LIBRARIES "${FREETYPE_LIBRARY}")
 
-if(FREETYPE_INCLUDE_DIR_freetype2 AND EXISTS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h")
-    file(STRINGS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h" freetype_version_str
+if(EXISTS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h")
+  set(FREETYPE_H "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h")
+elseif(EXISTS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype.h")
+  set(FREETYPE_H "${FREETYPE_INCLUDE_DIR_freetype2}/freetype.h")
+endif()
+
+if(FREETYPE_INCLUDE_DIR_freetype2 AND FREETYPE_H)
+    file(STRINGS "${FREETYPE_H}" freetype_version_str
          REGEX "^#[\t ]*define[\t ]+FREETYPE_(MAJOR|MINOR|PATCH)[\t ]+[0-9]+$")
 
     unset(FREETYPE_VERSION_STRING)
