$NetBSD: patch-cmake_compilers_GNU.cmake,v 1.6 2025/06/20 14:20:32 nia Exp $

Remove security hardening flags so that the mk/ infrastructure can pass
them depending on whether they are supported by the target platform.

--- cmake/compilers/GNU.cmake.orig	2025-06-20 14:05:05.891314120 +0000
+++ cmake/compilers/GNU.cmake
@@ -103,15 +103,6 @@ endif ()
 
 # Gnu flags to prevent compiler from optimizing out security checks
 set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -fno-strict-overflow -fno-delete-null-pointer-checks -fwrapv)
-set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -Wformat -Wformat-security -Werror=format-security
-    -fstack-protector-strong )
-# -z switch is not supported on MacOS and MinGW
-if (NOT APPLE AND NOT MINGW)
-    set(TBB_LIB_LINK_FLAGS ${TBB_LIB_LINK_FLAGS} -Wl,-z,relro,-z,now,-z,noexecstack)
-endif()
-if (NOT CMAKE_CXX_FLAGS MATCHES "_FORTIFY_SOURCE")
-  set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} $<$<NOT:$<CONFIG:Debug>>:-D_FORTIFY_SOURCE=2> )
-endif ()
 
 # TBB malloc settings
 set(TBBMALLOC_LIB_COMPILE_FLAGS -fno-rtti -fno-exceptions)
