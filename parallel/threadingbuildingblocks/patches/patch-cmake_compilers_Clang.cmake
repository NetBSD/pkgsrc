$NetBSD: patch-cmake_compilers_Clang.cmake,v 1.5 2026/07/23 12:28:40 prlw1 Exp $

Remove security hardening flags so that the mk/ infrastructure can pass
them depending on whether they are supported by the target platform.

--- cmake/compilers/Clang.cmake.orig	2026-07-19 16:53:28.896273751 +0000
+++ cmake/compilers/Clang.cmake
@@ -97,11 +97,6 @@ endif()
     endif()
 endif()
 
-# -z switch is not supported on MacOS and Windows
-if (NOT APPLE AND NOT WIN32)
-    set(TBB_LIB_LINK_FLAGS ${TBB_LIB_LINK_FLAGS} -Wl,-z,relro,-z,now,-z,noexecstack)
-endif()
-
 set(TBB_COMMON_LINK_LIBS ${CMAKE_DL_LIBS})
 
 if (NOT CMAKE_CXX_FLAGS MATCHES "_FORTIFY_SOURCE")
