$NetBSD: patch-src_gallium_drivers_llvmpipe_lp__state__setup.c,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  14926330703bb5ea6a84c845e192021f057f9401

--- src/gallium/drivers/llvmpipe/lp_state_setup.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/drivers/llvmpipe/lp_state_setup.c
@@ -624,8 +624,7 @@ set_noalias(LLVMBuilderRef builder,
    int i;
    for(i = 0; i < nr_args; ++i)
       if(LLVMGetTypeKind(arg_types[i]) == LLVMPointerTypeKind)
-         LLVMAddAttribute(LLVMGetParam(function, i),
-            LLVMNoAliasAttribute);
+         lp_add_function_attr(function, i + 1, LP_FUNC_ATTR_NOALIAS);
 }
 
 static void
