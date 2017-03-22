$NetBSD: patch-src_gallium_auxiliary_draw_draw__llvm.c,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  8bdd52c8f3595128cbc1da4f23cdb10ff861a6ef

--- src/gallium/auxiliary/draw/draw_llvm.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/auxiliary/draw/draw_llvm.c
@@ -1612,8 +1612,7 @@ draw_llvm_generate(struct draw_llvm *llv
    LLVMSetFunctionCallConv(variant_func, LLVMCCallConv);
    for (i = 0; i < num_arg_types; ++i)
       if (LLVMGetTypeKind(arg_types[i]) == LLVMPointerTypeKind)
-         LLVMAddAttribute(LLVMGetParam(variant_func, i),
-                          LLVMNoAliasAttribute);
+         lp_add_function_attr(variant_func, i + 1, LP_FUNC_ATTR_NOALIAS);
 
    context_ptr               = LLVMGetParam(variant_func, 0);
    io_ptr                    = LLVMGetParam(variant_func, 1);
@@ -2158,8 +2157,7 @@ draw_gs_llvm_generate(struct draw_llvm *
 
    for (i = 0; i < Elements(arg_types); ++i)
       if (LLVMGetTypeKind(arg_types[i]) == LLVMPointerTypeKind)
-         LLVMAddAttribute(LLVMGetParam(variant_func, i),
-                          LLVMNoAliasAttribute);
+         lp_add_function_attr(variant_func, i + 1, LP_FUNC_ATTR_NOALIAS);
 
    context_ptr               = LLVMGetParam(variant_func, 0);
    input_array               = LLVMGetParam(variant_func, 1);
