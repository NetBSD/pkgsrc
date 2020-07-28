$NetBSD: patch-core_cmake_BareosSetVariableDefaults.cmake,v 1.1 2020/07/28 06:36:29 kardel Exp $

provide absolute paths

--- core/cmake/BareosSetVariableDefaults.cmake.orig	2020-06-22 13:09:58.135202289 +0000
+++ core/cmake/BareosSetVariableDefaults.cmake
@@ -124,7 +124,7 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin"
 
   # logdir
   if(NOT DEFINED logdir)
-    set(logdir "${CMAKE_INSTALL_LOCALSTATEDIR}/log/${CMAKE_PROJECT_NAME}")
+    set(logdir "/${CMAKE_INSTALL_LOCALSTATEDIR}/log/${CMAKE_PROJECT_NAME}")
   endif()
 
   # datarootdir
@@ -412,6 +412,8 @@ endif()
 # ndmp
 if(NOT DEFINED ndmp)
   set(ndmp ON)
+else()
+  set(ndmp OFF)
 endif()
 
 # ipv6
