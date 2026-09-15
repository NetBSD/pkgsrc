$NetBSD: patch-lib_Target_Hexagon_RDFCopy.cpp,v 1.1 2026/09/15 21:10:07 tnn Exp $

https://github.com/llvm/llvm-project/commit/a558d656043734cc4d02e0a0a12e4c308c28f8c7.patch

--- lib/Target/Hexagon/RDFCopy.cpp.orig	2025-12-12 10:35:47.000000000 +0000
+++ lib/Target/Hexagon/RDFCopy.cpp
@@ -108,7 +108,7 @@ bool CopyPropagation::scanBlock(MachineB
   for (NodeAddr<InstrNode*> IA : BA.Addr->members(DFG)) {
     if (DFG.IsCode<NodeAttrs::Stmt>(IA)) {
       NodeAddr<StmtNode*> SA = IA;
-      EqualityMap EM(std::less<RegisterRef>(DFG.getPRI()));
+      EqualityMap EM(RegisterRefLess(DFG.getPRI()));
       if (interpretAsCopy(SA.Addr->getCode(), EM))
         recordCopy(SA, EM);
     }
