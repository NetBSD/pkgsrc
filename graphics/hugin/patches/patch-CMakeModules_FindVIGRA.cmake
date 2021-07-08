$NetBSD: patch-CMakeModules_FindVIGRA.cmake,v 1.1 2021/07/08 21:27:07 markd Exp $

openexr3 patch

--- CMakeModules/FindVIGRA.cmake.orig	2018-07-23 17:20:45.000000000 +0000
+++ CMakeModules/FindVIGRA.cmake
@@ -74,7 +74,7 @@ IF (VIGRA_FOUND)
         OUTPUT_STRIP_TRAILING_WHITESPACE
       )
       STRING(TOLOWER "${OUTPUT_LDD_VIGRA}" OUTPUT_LDD_VIGRA_LOWER)
-      IF(NOT "${OUTPUT_LDD_VIGRA_LOWER}" MATCHES "libilmimf")
+      IF(NOT "${OUTPUT_LDD_VIGRA_LOWER}" MATCHES "libopenexr")
         MESSAGE(FATAL_ERROR "Libvigraimpex found. But vigraimpex seems to compiled without OpenEXR support. OpenEXR support is required for Hugin.")
       ENDIF()
     ELSE()
