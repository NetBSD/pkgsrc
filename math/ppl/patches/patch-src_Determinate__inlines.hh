$NetBSD: patch-src_Determinate__inlines.hh,v 1.1 2017/02/28 15:01:27 joerg Exp $

--- src/Determinate_inlines.hh.orig	2017-02-27 13:25:22.383118938 +0000
+++ src/Determinate_inlines.hh
@@ -288,7 +288,7 @@ operator()(Determinate& x, const Determi
 template <typename PSET>
 template <typename Binary_Operator_Assign>
 inline
-Determinate<PSET>::Binary_Operator_Assign_Lifter<Binary_Operator_Assign>
+typename Determinate<PSET>::template Binary_Operator_Assign_Lifter<Binary_Operator_Assign>
 Determinate<PSET>::lift_op_assign(Binary_Operator_Assign op_assign) {
   return Binary_Operator_Assign_Lifter<Binary_Operator_Assign>(op_assign);
 }
