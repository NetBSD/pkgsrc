$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_select.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/select.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/select.ll
@@ -13,8 +13,8 @@
 ; CHECK-SPIRV: TypeFunction [[#FUNC_TYPE:]] [[#INT32]] [[#INT32]]
 ; CHECK-SPIRV: TypePointer [[#FUNC_PTR_TYPE:]] [[#]] [[#FUNC_TYPE]]
 ; CHECK-SPIRV: TypePointer [[#FUNC_PTR_ALLOCA_TYPE:]] [[#]] [[#FUNC_PTR_TYPE]]
-; CHECK-SPIRV-DAG: ConstFunctionPointerINTEL [[#FUNC_PTR_TYPE]] [[#BARPTR:]] [[#BAR]]
-; CHECK-SPIRV-DAG: ConstFunctionPointerINTEL [[#FUNC_PTR_TYPE]] [[#BAZPTR:]] [[#BAZ]]
+; CHECK-SPIRV-DAG: ConstantFunctionPointerINTEL [[#FUNC_PTR_TYPE]] [[#BARPTR:]] [[#BAR]]
+; CHECK-SPIRV-DAG: ConstantFunctionPointerINTEL [[#FUNC_PTR_TYPE]] [[#BAZPTR:]] [[#BAZ]]
 ; CHECK-SPIRV: Function [[#]] [[#KERNEL_ID]]
 ; CHECK-SPIRV: Variable [[#FUNC_PTR_ALLOCA_TYPE]] [[#FPTR:]]
 ; CHECK-SPIRV: Select [[#FUNC_PTR_TYPE]] [[#SELECT:]] [[#]] [[#BARPTR]] [[#BAZPTR]]
