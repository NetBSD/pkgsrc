$NetBSD: patch-CMake_vtkModule.cmake,v 1.1 2025/02/24 17:23:20 adam Exp $

Do not restrict external module version.
This allows to use a newer version when available.

--- CMake/vtkModule.cmake.orig	2025-02-24 11:29:04.556570674 +0000
+++ CMake/vtkModule.cmake
@@ -5349,7 +5349,6 @@ macro (vtk_module_find_package)
   endif ()
 
   find_package("${_vtk_find_package_PACKAGE}"
-    ${_vtk_find_package_VERSION}
     ${_vtk_find_package_config}
     COMPONENTS          ${_vtk_find_package_COMPONENTS}
     OPTIONAL_COMPONENTS ${_vtk_find_package_OPTIONAL_COMPONENTS})
