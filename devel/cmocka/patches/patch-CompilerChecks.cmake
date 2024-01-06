$NetBSD: patch-CompilerChecks.cmake,v 1.2 2024/01/06 09:07:07 pin Exp $

Let PkgSrc handle security features.

--- CompilerChecks.cmake.orig	2024-01-05 09:27:46.665856486 +0000
+++ CompilerChecks.cmake
@@ -66,29 +66,6 @@ if (UNIX)
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
