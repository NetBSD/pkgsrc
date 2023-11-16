$NetBSD: patch-src_llvm-project_llvm_lib_Target_PowerPC_PPCISelLowering.cpp,v 1.1 2023/11/16 09:49:12 he Exp $

Backport change from LLVM 17.0.3, so that rust builds
with the embedded LLVM.
Ref. https://github.com/rust-lang/rust/issues/116845.

--- src/llvm-project/llvm/lib/Target/PowerPC/PPCISelLowering.cpp.orig	2023-10-03 02:52:40.000000000 +0000
+++ src/llvm-project/llvm/lib/Target/PowerPC/PPCISelLowering.cpp
@@ -15527,7 +15527,7 @@ SDValue PPCTargetLowering::PerformDAGCom
       break;
     SDValue ConstOp = DAG.getConstant(Imm, dl, MVT::i32);
     SDValue NarrowAnd = DAG.getNode(ISD::AND, dl, MVT::i32, NarrowOp, ConstOp);
-    return DAG.getAnyExtOrTrunc(NarrowAnd, dl, N->getValueType(0));
+    return DAG.getZExtOrTrunc(NarrowAnd, dl, N->getValueType(0));
   }
   case ISD::SHL:
     return combineSHL(N, DCI);
