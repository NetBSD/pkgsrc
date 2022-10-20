$NetBSD: patch-cmake_BTApplication.cmake,v 1.2 2022/10/20 15:49:12 nros Exp $

* Treat apple like other unix-like systems

--- cmake/BTApplication.cmake.orig	2022-10-20 15:46:45.872225854 +0000
+++ cmake/BTApplication.cmake
@@ -58,7 +58,7 @@ ELSE()
   ADD_COMPILE_OPTIONS("-fPIE" "-fexceptions")
   SET(CMAKE_CXX_FLAGS_RELEASE "")
   SET(CMAKE_CXX_FLAGS_DEBUG "")
-  IF(APPLE)
+  IF(false)
     SET(T "/Applications/Xcode_12.4.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/")
     LIST(APPEND BibleTime_CXXFLAGS
         "-mmacosx-version-min=10.12"
@@ -88,7 +88,7 @@ GET_SOURCE_FILE_PROPERTY(d
     "${CMAKE_CURRENT_SOURCE_DIR}/src/util/directory.cpp" COMPILE_DEFINITIONS)
 IF(DEFINED BT_RUNTIME_DOCDIR)
     LIST(APPEND d "BT_RUNTIME_DOCDIR=\"${BT_RUNTIME_DOCDIR}\"")
-ELSEIF(APPLE OR MSVC)
+ELSEIF(MSVC)
     LIST(APPEND d "BT_RUNTIME_DOCDIR=\"${BT_DOCDIR}\"")
 ELSE()
     LIST(APPEND d "BT_RUNTIME_DOCDIR=\"${BT_DOCDIR_ABSOLUTE}\"")
@@ -128,7 +128,7 @@ FILE(GLOB_RECURSE bibletime_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/*.qrc"
 )
-IF(APPLE)
+IF(false)
     ADD_EXECUTABLE("bibletime" MACOSX_BUNDLE ${bibletime_SOURCES})
     SET_TARGET_PROPERTIES("bibletime" PROPERTIES OUTPUT_NAME "BibleTime")
 ELSEIF(MSVC)
@@ -213,7 +213,7 @@ IF(MSVC) # Windows:
     SET(bibletime_PDB "${bibletime_BINARY_DIR}/Debug/bibletime.pdb")
     INSTALL(FILES "${bibletime_PDB}" DESTINATION "${BT_BINDIR}")
   ENDIF()
-ELSEIF(APPLE) # OS X:
+ELSEIF(false) # OS X:
   # sword locale information, needed for DMG image
   FILE(GLOB INSTALL_SWORD_LOCALE_LIST "${Sword_INCLUDE_DIRS}/../../share/sword/locales.d/*")
   INSTALL(FILES ${INSTALL_SWORD_LOCALE_LIST}
@@ -228,7 +228,7 @@ ENDIF()
 #
 IF(WIN32 AND NOT UNIX)
   INCLUDE("${CMAKE_CURRENT_SOURCE_DIR}/cmake/BTBinaryPackageWindows.cmake")
-ELSEIF(APPLE)
+ELSEIF(false)
   INCLUDE("${CMAKE_CURRENT_SOURCE_DIR}/cmake/BTBinaryPackageMacOS.cmake")
 ENDIF()
 
