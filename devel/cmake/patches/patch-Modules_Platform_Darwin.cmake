$NetBSD: patch-Modules_Platform_Darwin.cmake,v 1.1 2020/07/31 16:03:13 adam Exp $

Prefer pkgsrc over system provided libraries.

--- Modules/Platform/Darwin.cmake.orig	2020-07-30 16:34:59.000000000 +0000
+++ Modules/Platform/Darwin.cmake
@@ -159,10 +159,10 @@ if(_CMAKE_OSX_SYSROOT_PATH)
   endforeach()
 
   if(EXISTS ${_CMAKE_OSX_SYSROOT_PATH}/usr/lib)
-    list(INSERT CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES 0 ${_CMAKE_OSX_SYSROOT_PATH}/usr/lib)
+    list(APPEND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES ${_CMAKE_OSX_SYSROOT_PATH}/usr/lib)
   endif()
   if(EXISTS ${_CMAKE_OSX_SYSROOT_PATH}/usr/local/lib)
-    list(INSERT CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES 0 ${_CMAKE_OSX_SYSROOT_PATH}/usr/local/lib)
+    list(APPEND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES ${_CMAKE_OSX_SYSROOT_PATH}/usr/local/lib)
   endif()
 endif()
 if (OSX_DEVELOPER_ROOT AND EXISTS "${OSX_DEVELOPER_ROOT}/Library/Frameworks")
@@ -218,13 +218,13 @@ unset(_apps_paths)
 include(Platform/UnixPaths)
 if(_CMAKE_OSX_SYSROOT_PATH)
   if(EXISTS ${_CMAKE_OSX_SYSROOT_PATH}/usr/include)
-    list(INSERT CMAKE_SYSTEM_PREFIX_PATH 0 ${_CMAKE_OSX_SYSROOT_PATH}/usr)
+    list(APPEND CMAKE_SYSTEM_PREFIX_PATH ${_CMAKE_OSX_SYSROOT_PATH}/usr)
     foreach(lang C CXX OBJC OBJCXX Swift)
       list(APPEND _CMAKE_${lang}_IMPLICIT_INCLUDE_DIRECTORIES_INIT ${_CMAKE_OSX_SYSROOT_PATH}/usr/include)
     endforeach()
   endif()
   if(EXISTS ${_CMAKE_OSX_SYSROOT_PATH}/usr/local/include)
-    list(INSERT CMAKE_SYSTEM_PREFIX_PATH 0 ${_CMAKE_OSX_SYSROOT_PATH}/usr/local)
+    list(APPEND CMAKE_SYSTEM_PREFIX_PATH ${_CMAKE_OSX_SYSROOT_PATH}/usr/local)
     foreach(lang C CXX OBJC OBJCXX Swift)
       list(APPEND _CMAKE_${lang}_IMPLICIT_INCLUDE_DIRECTORIES_INIT ${_CMAKE_OSX_SYSROOT_PATH}/usr/local/include)
     endforeach()
