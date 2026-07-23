$NetBSD: patch-cmake_compilers_GNU.cmake,v 1.7 2026/07/23 12:28:40 prlw1 Exp $

Remove security hardening flags so that the mk/ infrastructure can pass
them depending on whether they are supported by the target platform.

--- cmake/compilers/GNU.cmake.orig	2026-07-19 16:53:28.901108647 +0000
+++ cmake/compilers/GNU.cmake
@@ -106,20 +106,6 @@ set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAG
 
 # Gnu flags to prevent compiler from optimizing out security checks
 set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -fno-strict-overflow -fno-delete-null-pointer-checks -fwrapv)
-set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -Wformat -Wformat-security -Werror=format-security
-    -fstack-protector-strong )
-if (CMAKE_SYSTEM_PROCESSOR MATCHES "(AMD64|amd64|i.86|x86)" AND NOT EMSCRIPTEN)
-    set(TBB_LIB_COMPILE_FLAGS ${TBB_LIB_COMPILE_FLAGS} $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},8.0>>:-fcf-protection=full>)
-endif ()
-set(TBB_LIB_COMPILE_FLAGS ${TBB_LIB_COMPILE_FLAGS} $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},8.0>>:-fstack-clash-protection>)
-
-# -z switch is not supported on MacOS and MinGW
-if (NOT APPLE AND NOT MINGW)
-    set(TBB_LIB_LINK_FLAGS ${TBB_LIB_LINK_FLAGS} -Wl,-z,relro,-z,now,-z,noexecstack)
-endif()
-if (NOT CMAKE_CXX_FLAGS MATCHES "_FORTIFY_SOURCE")
-  set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} $<$<NOT:$<CONFIG:Debug>>:-D_FORTIFY_SOURCE=2> )
-endif ()
 
 if (TBB_FILE_TRIM AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8 AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Intel")
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -ffile-prefix-map=${NATIVE_TBB_PROJECT_ROOT_DIR}/= -ffile-prefix-map=${NATIVE_TBB_RELATIVE_BIN_PATH}/=)
