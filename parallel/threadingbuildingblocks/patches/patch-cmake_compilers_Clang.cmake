$NetBSD: patch-cmake_compilers_Clang.cmake,v 1.4 2025/06/20 14:20:32 nia Exp $

Remove security hardening flags so that the mk/ infrastructure can pass
them depending on whether they are supported by the target platform.

--- cmake/compilers/Clang.cmake.orig	2025-06-20 14:04:56.076853522 +0000
+++ cmake/compilers/Clang.cmake
@@ -65,11 +65,6 @@ endif()
 # Clang flags to prevent compiler from optimizing out security checks
 set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -Wformat -Wformat-security -Werror=format-security -fPIC $<$<NOT:$<BOOL:${EMSCRIPTEN}>>:-fstack-protector-strong>)
 
-# -z switch is not supported on MacOS
-if (NOT APPLE)
-    set(TBB_LIB_LINK_FLAGS ${TBB_LIB_LINK_FLAGS} -Wl,-z,relro,-z,now)
-endif()
-
 set(TBB_COMMON_LINK_LIBS ${CMAKE_DL_LIBS})
 
 if (NOT CMAKE_CXX_FLAGS MATCHES "_FORTIFY_SOURCE")
