$NetBSD: patch-test_constexpr__vector.ll,v 1.1 2021/11/23 20:55:44 wiz Exp $

https://github.com/KhronosGroup/SPIRV-LLVM-Translator/pull/1265

--- test/constexpr_vector.ll.orig	2021-10-15 21:15:19.000000000 +0000
+++ test/constexpr_vector.ll
@@ -62,10 +62,10 @@
 ; CHECK-SPIRV-DAG: 4 TypePointer [[StorePtr:[0-9]+]] 7 [[TypeVec16]]
 ; CHECK-SPIRV-DAG: 3 Undef [[TypeVec16]] [[TypeUndefV16:[0-9]+]]
 ; CHECK-SPIRV-DAG: 3 Undef [[TypeVec64]] [[TypeUndefV64:[0-9]+]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[FuncPtrTy:[0-9]+]] [[F1Ptr:[0-9]+]] [[F1]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[FuncPtrTy]] [[F2Ptr:[0-9]+]] [[F2]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[FuncPtrTy]] [[F11Ptr:[0-9]+]] [[F1]]
-; CHECK-SPIRV-DAG: 4 ConstFunctionPointerINTEL [[FuncPtrTy]] [[F21Ptr:[0-9]+]] [[F2]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[FuncPtrTy:[0-9]+]] [[F1Ptr:[0-9]+]] [[F1]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[FuncPtrTy]] [[F2Ptr:[0-9]+]] [[F2]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[FuncPtrTy]] [[F11Ptr:[0-9]+]] [[F1]]
+; CHECK-SPIRV-DAG: 4 ConstantFunctionPointerINTEL [[FuncPtrTy]] [[F21Ptr:[0-9]+]] [[F2]]
 
 ; CHECK-SPIRV: 4 ConvertPtrToU [[TypeInt64]] [[Ptr1:[0-9]+]] [[F1Ptr]]
 ; CHECK-SPIRV: 4 Bitcast [[TypeVec8]] [[Vec1:[0-9]+]] [[Ptr1]]
