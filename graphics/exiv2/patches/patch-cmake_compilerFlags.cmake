$NetBSD: patch-cmake_compilerFlags.cmake,v 1.5 2021/11/07 12:09:12 wiz Exp $

Gcc on some platforms does not support -fcf-protection.

--- cmake/compilerFlags.cmake.orig	2021-10-21 17:01:10.000000000 +0000
+++ cmake/compilerFlags.cmake
@@ -28,7 +28,9 @@ if ( MINGW OR UNIX OR MSYS ) # MINGW, Li
             if (NOT APPLE) # Don't know why this isn't working correctly on Apple with M1 processor
                 check_cxx_compiler_flag(-fstack-clash-protection HAS_FSTACK_CLASH_PROTECTION)
             endif()
+            if (NOT (${CMAKE_SYSTEM_PROCESSOR} MATCHES "sparc.*|aarch64.*"))
             check_cxx_compiler_flag(-fcf-protection HAS_FCF_PROTECTION)
+            endif()
             check_cxx_compiler_flag(-fstack-protector-strong HAS_FSTACK_PROTECTOR_STRONG)
             if(HAS_FSTACK_CLASH_PROTECTION)
                 add_compile_options(-fstack-clash-protection)
