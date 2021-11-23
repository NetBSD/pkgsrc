$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_function-pointer.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/function-pointer.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/function-pointer.ll
@@ -24,7 +24,7 @@
 ; CHECK-SPIRV: TypeFunction [[FOO_TYPE_ID:[0-9]+]] [[TYPE_INT_ID]] [[TYPE_INT_ID]]
 ; CHECK-SPIRV: TypePointer [[FOO_PTR_ID:[0-9]+]] {{[0-9]+}} [[FOO_TYPE_ID]]
 ; CHECK-SPIRV: TypePointer [[FOO_PTR_ALLOCA_ID:[0-9]+]] 7 [[FOO_PTR_ID]]
-; CHECK-SPIRV: ConstFunctionPointerINTEL [[FOO_PTR_ID]] [[FOO_PTR:[0-9]+]] [[FOO_ID:[0-9]+]]
+; CHECK-SPIRV: ConstantFunctionPointerINTEL [[FOO_PTR_ID]] [[FOO_PTR:[0-9]+]] [[FOO_ID:[0-9]+]]
 ;
 ; CHECK-SPIRV: Function {{[0-9]+}} [[FOO_ID]] {{[0-9]+}} [[FOO_TYPE_ID]]
 ; CHECK-SPIRV: Function {{[0-9]+}} [[KERNEL_ID]]
