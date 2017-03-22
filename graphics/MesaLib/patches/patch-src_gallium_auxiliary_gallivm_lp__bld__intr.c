$NetBSD: patch-src_gallium_auxiliary_gallivm_lp__bld__intr.c,v 1.1 2017/03/22 20:22:31 markd Exp $

llvm api change
commit  8bdd52c8f3595128cbc1da4f23cdb10ff861a6ef

--- src/gallium/auxiliary/gallivm/lp_bld_intr.c.orig	2016-05-09 12:20:52.000000000 +0000
+++ src/gallium/auxiliary/gallivm/lp_bld_intr.c
@@ -45,6 +45,7 @@
 
 
 #include "util/u_debug.h"
+#include "util/u_math.h"
 
 #include "lp_bld_const.h"
 #include "lp_bld_intr.h"
@@ -75,6 +76,65 @@ lp_declare_intrinsic(LLVMModuleRef modul
    return function;
 }
 
+#if HAVE_LLVM < 0x0400
+static LLVMAttribute lp_attr_to_llvm_attr(enum lp_func_attr attr)
+{
+   switch (attr) {
+   case LP_FUNC_ATTR_ALWAYSINLINE: return LLVMAlwaysInlineAttribute;
+   case LP_FUNC_ATTR_BYVAL: return LLVMByValAttribute;
+   case LP_FUNC_ATTR_INREG: return LLVMInRegAttribute;
+   case LP_FUNC_ATTR_NOALIAS: return LLVMNoAliasAttribute;
+   case LP_FUNC_ATTR_NOUNWIND: return LLVMNoUnwindAttribute;
+   case LP_FUNC_ATTR_READNONE: return LLVMReadNoneAttribute;
+   case LP_FUNC_ATTR_READONLY: return LLVMReadOnlyAttribute;
+   default:
+      _debug_printf("Unhandled function attribute: %x\n", attr);
+      return 0;
+   }
+}
+
+#else
+
+static const char *attr_to_str(enum lp_func_attr attr)
+{
+   switch (attr) {
+   case LP_FUNC_ATTR_ALWAYSINLINE: return "alwaysinline";
+   case LP_FUNC_ATTR_BYVAL: return "byval";
+   case LP_FUNC_ATTR_INREG: return "inreg";
+   case LP_FUNC_ATTR_NOALIAS: return "noalias";
+   case LP_FUNC_ATTR_NOUNWIND: return "nounwind";
+   case LP_FUNC_ATTR_READNONE: return "readnone";
+   case LP_FUNC_ATTR_READONLY: return "readonly";
+   default:
+      _debug_printf("Unhandled function attribute: %x\n", attr);
+      return 0;
+   }
+}
+
+#endif
+
+void
+lp_add_function_attr(LLVMValueRef function,
+                     int attr_idx,
+                     enum lp_func_attr attr)
+{
+
+#if HAVE_LLVM < 0x0400
+   LLVMAttribute llvm_attr = lp_attr_to_llvm_attr(attr);
+   if (attr_idx == -1) {
+      LLVMAddFunctionAttr(function, llvm_attr);
+   } else {
+      LLVMAddAttribute(LLVMGetParam(function, attr_idx - 1), llvm_attr);
+   }
+#else
+   LLVMContextRef context = LLVMGetModuleContext(LLVMGetGlobalParent(function));
+   const char *attr_name = attr_to_str(attr);
+   unsigned kind_id = LLVMGetEnumAttributeKindForName(attr_name,
+                                                      strlen(attr_name));
+   LLVMAttributeRef llvm_attr = LLVMCreateEnumAttribute(context, kind_id, 0);
+   LLVMAddAttributeAtIndex(function, attr_idx, llvm_attr);
+#endif
+}
 
 LLVMValueRef
 lp_build_intrinsic(LLVMBuilderRef builder,
@@ -82,7 +142,7 @@ lp_build_intrinsic(LLVMBuilderRef builde
                    LLVMTypeRef ret_type,
                    LLVMValueRef *args,
                    unsigned num_args,
-                   LLVMAttribute attr)
+                   unsigned attr_mask)
 {
    LLVMModuleRef module = LLVMGetGlobalParent(LLVMGetBasicBlockParent(LLVMGetInsertBlock(builder)));
    LLVMValueRef function;
@@ -101,8 +161,12 @@ lp_build_intrinsic(LLVMBuilderRef builde
 
       function = lp_declare_intrinsic(module, name, ret_type, arg_types, num_args);
 
-      if (attr)
-          LLVMAddFunctionAttr(function, attr);
+      attr_mask |= LP_FUNC_ATTR_NOUNWIND;
+
+      while (attr_mask) {
+         enum lp_func_attr attr = 1 << u_bit_scan(&attr_mask);
+         lp_add_function_attr(function, -1, attr);
+      }
    }
 
    return LLVMBuildCall(builder, function, args, num_args, "");
