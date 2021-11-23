$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_bitcast.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/bitcast.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/bitcast.ll
@@ -18,7 +18,7 @@
 ; CHECK-SPIRV: TypeFunction [[#DEST_TY:]] [[#]] [[#]]
 ; CHECK-SPIRV: TypePointer [[#DEST_TY_PTR:]] [[#]] [[#DEST_TY]]
 ; CHECK-SPIRV: TypePointer [[#FOO_TY_PTR:]] [[#]] [[#FOO_TY]]
-; CHECK-SPIRV: ConstFunctionPointerINTEL [[#FOO_TY_PTR]] [[#FOO_PTR:]] [[#FOO:]]
+; CHECK-SPIRV: ConstantFunctionPointerINTEL [[#FOO_TY_PTR]] [[#FOO_PTR:]] [[#FOO:]]
 ; CHECK-SPIRV: Function [[#]] [[#FOO]] [[#]] [[#FOO_TY]]
 
 ; CHECK-SPIRV: Bitcast [[#DEST_TY_PTR]] [[#]] [[#FOO_PTR]]
