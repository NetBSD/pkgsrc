$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_const-function-pointer.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/const-function-pointer.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/const-function-pointer.ll
@@ -14,8 +14,8 @@
 ; CHECK-SPIRV-DAG: Constant [[Int32]] [[XArg:[0-9]+]] 32
 ; CHECK-SPIRV-DAG: Constant [[Int32]] [[YArg:[0-9]+]] 2
 
-; CHECK-SPIRV: ConstFunctionPointerINTEL {{[0-9]+}} [[F1:[0-9]+]] [[F1Name]]
-; CHECK-SPIRV: ConstFunctionPointerINTEL {{[0-9]+}} [[F2:[0-9]+]] [[F2Name]]
+; CHECK-SPIRV: ConstantFunctionPointerINTEL {{[0-9]+}} [[F1:[0-9]+]] [[F1Name]]
+; CHECK-SPIRV: ConstantFunctionPointerINTEL {{[0-9]+}} [[F2:[0-9]+]] [[F2Name]]
 ; CHECK-SPIRV: ConstantComposite {{[0-9]+}} [[ConstComp:[0-9]+]] [[F1]] [[F2]]
 ; CHECK-SPIRV: Variable {{[0-9]+}} [[Var:[0-9]+]] {{[0-9]+}} [[ConstComp]]
 
