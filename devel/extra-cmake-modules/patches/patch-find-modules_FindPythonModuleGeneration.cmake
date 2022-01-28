$NetBSD: patch-find-modules_FindPythonModuleGeneration.cmake,v 1.1 2022/01/28 09:00:36 wiz Exp $

Allow python 3.10 and newer.

--- find-modules/FindPythonModuleGeneration.cmake.orig	2021-06-01 13:02:21.000000000 +0000
+++ find-modules/FindPythonModuleGeneration.cmake
@@ -162,7 +162,7 @@ endif()
 
 if (NOT GPB_PYTHON3_LIBRARY)
   set(_PYTHON3_MIN_VERSION 4)
-  set(_PYTHON3_MAX_VERSION 10)
+  set(_PYTHON3_MAX_VERSION 99)
 
   _find_python(3 ${_PYTHON3_MAX_VERSION}) # Canary check
 
