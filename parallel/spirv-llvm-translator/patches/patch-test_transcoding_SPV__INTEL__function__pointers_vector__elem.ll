$NetBSD: patch-test_transcoding_SPV__INTEL__function__pointers_vector__elem.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/transcoding/SPV_INTEL_function_pointers/vector_elem.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/transcoding/SPV_INTEL_function_pointers/vector_elem.ll
@@ -9,8 +9,8 @@
 ; CHECK-SPIRV: 4 TypePointer [[TypePtr:[0-9]+]] {{[0-9]+}} [[TypeFunc]]
 ; CHECK-SPIRV: 4 TypeVector [[TypeVec:[0-9]+]] [[TypePtr]] [[TypeInt32]]
 ; CHECK-SPIRV-DAG: 3 Undef [[TypeVec]] [[TypeUndef:[0-9]+]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[TypePtr]] [[F1Ptr:[0-9]+]] [[F1]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[TypePtr]] [[F2Ptr:[0-9]+]] [[F2]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[TypePtr]] [[F1Ptr:[0-9]+]] [[F1]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[TypePtr]] [[F2Ptr:[0-9]+]] [[F2]]
 
 ; CHECK-SPIRV: 6 CompositeInsert [[TypeVec]] [[NewVec0:[0-9]+]] [[F1Ptr]] [[TypeUndef]] 0
 ; CHECK-SPIRV: 6 CompositeInsert [[TypeVec]] [[NewVec1:[0-9]+]] [[F2Ptr]] [[NewVec0]] 1
