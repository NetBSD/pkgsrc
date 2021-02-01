$NetBSD: patch-core_cmake_BareosSetVariableDefaults.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	disable ndmp due to missing xdr marshalling code

--- core/cmake/BareosSetVariableDefaults.cmake.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/cmake/BareosSetVariableDefaults.cmake
@@ -413,6 +413,8 @@ endif()
 # ndmp
 if(NOT DEFINED ndmp)
   set(ndmp ON)
+else()
+  set(ndmp OFF)
 endif()
 
 # ipv6
