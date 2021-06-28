$NetBSD: patch-cmake_compilerFlags.cmake,v 1.4 2021/06/28 07:50:44 wiz Exp $

Gcc on some platforms does not support -fcf-protection.

--- cmake/compilerFlags.cmake.orig	2021-06-15 14:08:36.000000000 +0000
+++ cmake/compilerFlags.cmake
@@ -26,7 +26,9 @@ if ( MINGW OR UNIX OR MSYS ) # MINGW, Li
         # This fails under Fedora - MinGW - Gcc 8.3
         if (NOT (MINGW OR CYGWIN OR CMAKE_HOST_SOLARIS))
             check_cxx_compiler_flag(-fstack-clash-protection HAS_FSTACK_CLASH_PROTECTION)
+            if (NOT (${CMAKE_SYSTEM_PROCESSOR} MATCHES "sparc.*|aarch64.*"))
             check_cxx_compiler_flag(-fcf-protection HAS_FCF_PROTECTION)
+            endif()
             check_cxx_compiler_flag(-fstack-protector-strong HAS_FSTACK_PROTECTOR_STRONG)
             if(HAS_FSTACK_CLASH_PROTECTION)
                 add_compile_options(-fstack-clash-protection)
