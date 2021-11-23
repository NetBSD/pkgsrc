$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_global__ctor__dtor.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/global_ctor_dtor.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/global_ctor_dtor.ll
@@ -22,9 +22,9 @@ target triple = "spir64-unknown-unknown"
 ; CHECK: TypeFunction {{[0-9]+}} [[TF:[0-9]+]]
 
 ; CHECK: TypePointer [[TP:[0-9]+]]
-; CHECK: ConstFunctionPointerINTEL [[TP]] [[FPCtor:[0-9]+]] [[NameCtor]]
+; CHECK: ConstantFunctionPointerINTEL [[TP]] [[FPCtor:[0-9]+]] [[NameCtor]]
 ; CHECK: ConstantComposite {{[0-9]+}} {{[0-9]+}} {{[0-9]+}} [[FPCtor]]
-; CHECK: ConstFunctionPointerINTEL [[TP]] [[FPDtor:[0-9]+]] [[NameDtor]]
+; CHECK: ConstantFunctionPointerINTEL [[TP]] [[FPDtor:[0-9]+]] [[NameDtor]]
 ; CHECK: ConstantComposite {{[0-9]+}} {{[0-9]+}} {{[0-9]+}} [[FPDtor]]
 
 ; CHECK: 5 Function [[TF]] [[NameCtor]] 0
