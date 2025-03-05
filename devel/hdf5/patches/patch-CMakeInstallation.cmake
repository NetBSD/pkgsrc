$NetBSD: patch-CMakeInstallation.cmake,v 1.1 2025/03/05 06:24:20 adam Exp $

Do not install files in top-level directory.

--- CMakeInstallation.cmake.orig	2025-03-03 16:53:10.157608369 +0000
+++ CMakeInstallation.cmake
@@ -189,7 +189,7 @@ endif ()
 #-----------------------------------------------------------------------------
 # Add Document File(s) to CMake Install
 #-----------------------------------------------------------------------------
-if (NOT HDF5_EXTERNALLY_CONFIGURED)
+if (FALSE)
   install (
       FILES ${HDF5_SOURCE_DIR}/COPYING
       DESTINATION ${HDF5_INSTALL_DATA_DIR}
