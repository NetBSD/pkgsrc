$NetBSD: patch-src_gallium_auxiliary_gallivm_lp__bld__intr.h,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  8bdd52c8f3595128cbc1da4f23cdb10ff861a6ef

--- src/gallium/auxiliary/gallivm/lp_bld_intr.h.orig	2016-05-09 12:20:52.000000000 +0000
+++ src/gallium/auxiliary/gallivm/lp_bld_intr.h
@@ -46,6 +46,16 @@
  */
 #define LP_MAX_FUNC_ARGS 32
 
+enum lp_func_attr {
+   LP_FUNC_ATTR_ALWAYSINLINE = (1 << 0),
+   LP_FUNC_ATTR_BYVAL        = (1 << 1),
+   LP_FUNC_ATTR_INREG        = (1 << 2),
+   LP_FUNC_ATTR_NOALIAS      = (1 << 3),
+   LP_FUNC_ATTR_NOUNWIND     = (1 << 4),
+   LP_FUNC_ATTR_READNONE     = (1 << 5),
+   LP_FUNC_ATTR_READONLY     = (1 << 6),
+   LP_FUNC_ATTR_LAST         = (1 << 7)
+};
 
 LLVMValueRef
 lp_declare_intrinsic(LLVMModuleRef module,
@@ -54,13 +64,18 @@ lp_declare_intrinsic(LLVMModuleRef modul
                      LLVMTypeRef *arg_types,
                      unsigned num_args);
 
+void
+lp_add_function_attr(LLVMValueRef function,
+                     int attr_idx,
+                     enum lp_func_attr attr);
+
 LLVMValueRef
 lp_build_intrinsic(LLVMBuilderRef builder,
                    const char *name,
                    LLVMTypeRef ret_type,
                    LLVMValueRef *args,
                    unsigned num_args,
-                   LLVMAttribute attr);
+                   unsigned attr_mask);
 
 
 LLVMValueRef
