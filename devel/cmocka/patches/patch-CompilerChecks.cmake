$NetBSD: patch-CompilerChecks.cmake,v 1.3 2025/07/23 08:09:09 pin Exp $

Let PkgSrc handle security features.

--- CompilerChecks.cmake.orig	2025-07-23 07:22:57.049057609 +0000
+++ CompilerChecks.cmake
@@ -64,29 +64,6 @@ if (UNIX)
         endif()
     endif()
 
-    check_c_compiler_flag_ssp("-fstack-protector-strong" WITH_STACK_PROTECTOR_STRONG)
-    if (WITH_STACK_PROTECTOR_STRONG)
-        list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-protector-strong")
-        # This is needed as Solaris has a seperate libssp
-        if (SOLARIS)
-            list(APPEND SUPPORTED_LINKER_FLAGS "-fstack-protector-strong")
-        endif()
-    else (WITH_STACK_PROTECTOR_STRONG)
-        check_c_compiler_flag_ssp("-fstack-protector" WITH_STACK_PROTECTOR)
-        if (WITH_STACK_PROTECTOR)
-            list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-protector")
-            # This is needed as Solaris has a seperate libssp
-            if (SOLARIS)
-                list(APPEND SUPPORTED_LINKER_FLAGS "-fstack-protector")
-            endif()
-        endif()
-    endif (WITH_STACK_PROTECTOR_STRONG)
-
-    check_c_compiler_flag_ssp("-fstack-clash-protection" WITH_STACK_CLASH_PROTECTION)
-    if (WITH_STACK_CLASH_PROTECTION)
-        list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-clash-protection")
-    endif()
-
     if (PICKY_DEVELOPER)
         add_c_compiler_flag("-Wno-error=deprecated-declarations" SUPPORTED_COMPILER_FLAGS)
         add_c_compiler_flag("-Wno-error=tautological-compare" SUPPORTED_COMPILER_FLAGS)
