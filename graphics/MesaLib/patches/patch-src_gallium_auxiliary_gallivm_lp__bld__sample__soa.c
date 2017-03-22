$NetBSD: patch-src_gallium_auxiliary_gallivm_lp__bld__sample__soa.c,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  8bdd52c8f3595128cbc1da4f23cdb10ff861a6ef

--- src/gallium/auxiliary/gallivm/lp_bld_sample_soa.c.orig	2016-05-09 12:20:52.000000000 +0000
+++ src/gallium/auxiliary/gallivm/lp_bld_sample_soa.c
@@ -60,6 +60,7 @@
 #include "lp_bld_struct.h"
 #include "lp_bld_quad.h"
 #include "lp_bld_pack.h"
+#include "lp_bld_intr.h"
 
 
 /**
@@ -3315,7 +3316,7 @@ lp_build_sample_soa_func(struct gallivm_
 
       for (i = 0; i < num_param; ++i) {
          if(LLVMGetTypeKind(arg_types[i]) == LLVMPointerTypeKind) {
-            LLVMAddAttribute(LLVMGetParam(function, i), LLVMNoAliasAttribute);
+            lp_add_function_attr(function, i + 1, LP_FUNC_ATTR_NOALIAS);
          }
       }
 
