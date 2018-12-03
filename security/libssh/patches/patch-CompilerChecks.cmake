$NetBSD: patch-CompilerChecks.cmake,v 1.1 2018/12/03 15:19:51 adam Exp $

Let PkgSrc handle security features.

--- CompilerChecks.cmake.orig	2018-12-03 09:27:44.000000000 +0000
+++ CompilerChecks.cmake
@@ -62,20 +62,7 @@ if (UNIX)
         endif()
     endif()
 
-    check_c_compiler_flag_ssp("-fstack-protector-strong" WITH_STACK_PROTECTOR_STRONG)
-    if (WITH_STACK_PROTECTOR_STRONG)
-        list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-protector-strong")
-    else (WITH_STACK_PROTECTOR_STRONG)
-        check_c_compiler_flag_ssp("-fstack-protector" WITH_STACK_PROTECTOR)
-        if (WITH_STACK_PROTECTOR)
-            list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-protector")
-        endif()
-    endif (WITH_STACK_PROTECTOR_STRONG)
 
-    check_c_compiler_flag_ssp("-fstack-clash-protection" WITH_STACK_CLASH_PROTECTION)
-    if (WITH_STACK_CLASH_PROTECTION)
-        list(APPEND SUPPORTED_COMPILER_FLAGS "-fstack-clash-protection")
-    endif()
 
     if (PICKY_DEVELOPER)
         add_c_compiler_flag("-Wno-error=deprecated-declarations" SUPPORTED_COMPILER_FLAGS)
