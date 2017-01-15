$NetBSD: patch-src_compiler_glsl_builtin__functions.cpp,v 1.1 2017/01/15 00:13:44 wiz Exp $

--- src/compiler/glsl/builtin_functions.cpp.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/compiler/glsl/builtin_functions.cpp
@@ -853,6 +853,7 @@ builtin_builder::builtin_builder()
 builtin_builder::~builtin_builder()
 {
    ralloc_free(mem_ctx);
+   mem_ctx = NULL;
 }
 
 ir_function_signature *
