$NetBSD: patch-Modules_FindPython_Support.cmake,v 1.5 2023/08/20 12:59:26 adam Exp $

Insist on select Python version for pkgsrc.

--- Modules/FindPython/Support.cmake.orig	2023-08-16 17:46:35.000000000 +0000
+++ Modules/FindPython/Support.cmake
@@ -27,7 +27,9 @@ endif()
 if (NOT DEFINED _${_PYTHON_PREFIX}_REQUIRED_VERSION_MAJOR)
   message (FATAL_ERROR "FindPython: INTERNAL ERROR")
 endif()
-if (_${_PYTHON_PREFIX}_REQUIRED_VERSION_MAJOR EQUAL "3")
+if (DEFINED PYVERSSUFFIX)
+  set(_${_PYTHON_PREFIX}_VERSIONS ${PYVERSSUFFIX})
+elseif (_${_PYTHON_PREFIX}_REQUIRED_VERSION_MAJOR EQUAL "3")
   set(_${_PYTHON_PREFIX}_VERSIONS 3.13 3.12 3.11 3.10 3.9 3.8 3.7 3.6 3.5 3.4 3.3 3.2 3.1 3.0)
 elseif (_${_PYTHON_PREFIX}_REQUIRED_VERSION_MAJOR EQUAL "2")
   set(_${_PYTHON_PREFIX}_VERSIONS 2.7 2.6 2.5 2.4 2.3 2.2 2.1 2.0)
