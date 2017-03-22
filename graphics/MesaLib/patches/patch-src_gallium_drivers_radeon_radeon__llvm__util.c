$NetBSD: patch-src_gallium_drivers_radeon_radeon__llvm__util.c,v 1.1 2017/03/22 20:22:31 markd Exp $

--- src/gallium/drivers/radeon/radeon_llvm_util.c.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/drivers/radeon/radeon_llvm_util.c
@@ -26,6 +26,13 @@
 
 #include "radeon_llvm_util.h"
 #include "util/u_memory.h"
+#include "gallivm/lp_bld_const.h"
+#include "gallivm/lp_bld_gather.h"
+#include "gallivm/lp_bld_flow.h"
+#include "gallivm/lp_bld_init.h"
+#include "gallivm/lp_bld_intr.h"
+#include "gallivm/lp_bld_misc.h"
+#include "gallivm/lp_bld_swizzle.h"
 
 #include <llvm-c/BitReader.h>
 #include <llvm-c/Core.h>
@@ -75,7 +82,7 @@ static void radeon_llvm_optimize(LLVMMod
 	for (fn = LLVMGetFirstFunction(mod); fn; fn = LLVMGetNextFunction(fn)) {
 		/* All the non-kernel functions have internal linkage */
 		if (LLVMGetLinkage(fn) == LLVMInternalLinkage) {
-			LLVMAddFunctionAttr(fn, LLVMAlwaysInlineAttribute);
+			lp_add_function_attr(fn, -1, LP_FUNC_ATTR_ALWAYSINLINE);
 		}
 	}
 
