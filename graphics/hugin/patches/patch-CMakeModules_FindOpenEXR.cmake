$NetBSD: patch-CMakeModules_FindOpenEXR.cmake,v 1.1 2021/07/08 21:27:07 markd Exp $

openexr3 patch

--- CMakeModules/FindOpenEXR.cmake.orig	2020-08-21 18:08:05.000000000 +0000
+++ CMakeModules/FindOpenEXR.cmake
@@ -11,6 +11,13 @@
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
 
+FIND_PACKAGE(OpenEXR CONFIG REQUIRED)
+IF (TARGET OpenEXR::OpenEXR)
+    SET(OPENEXR_FOUND TRUE)
+    SET(OPENEXR_INCLUDE_DIR OpenEXR::OpenEXR)
+    SET(OPENEXR_LIBRARIES OpenEXR::OpenEXR)
+ENDIF()
+
 if (OPENEXR_INCLUDE_DIR AND OPENEXR_LIBRARIES)
   # in cache already
   SET(OPENEXR_FOUND TRUE)
