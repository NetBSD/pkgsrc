$NetBSD: patch-lib_Target_Hexagon_RDFCopy.h,v 1.1 2026/09/15 21:10:07 tnn Exp $

https://github.com/llvm/llvm-project/commit/a558d656043734cc4d02e0a0a12e4c308c28f8c7.patch

--- lib/Target/Hexagon/RDFCopy.h.orig	2025-12-12 10:35:47.000000000 +0000
+++ lib/Target/Hexagon/RDFCopy.h
@@ -25,8 +25,8 @@ class MachineInstr;
 namespace rdf {
 
   struct CopyPropagation {
-    CopyPropagation(DataFlowGraph &dfg) : MDT(dfg.getDT()), DFG(dfg),
-        RDefMap(std::less<RegisterRef>(DFG.getPRI())) {}
+    CopyPropagation(DataFlowGraph &dfg)
+        : MDT(dfg.getDT()), DFG(dfg), RDefMap(RegisterRefLess(DFG.getPRI())) {}
 
     virtual ~CopyPropagation() = default;
 
@@ -35,7 +35,7 @@ namespace rdf {
     bool trace() const { return Trace; }
     DataFlowGraph &getDFG() { return DFG; }
 
-    using EqualityMap = std::map<RegisterRef, RegisterRef>;
+    using EqualityMap = std::map<RegisterRef, RegisterRef, RegisterRefLess>;
     virtual bool interpretAsCopy(const MachineInstr *MI, EqualityMap &EM);
 
   private:
@@ -45,7 +45,7 @@ namespace rdf {
     bool Trace = false;
 
     // map: register -> (map: stmt -> reaching def)
-    std::map<RegisterRef,std::map<NodeId,NodeId>> RDefMap;
+    std::map<RegisterRef, std::map<NodeId, NodeId>, RegisterRefLess> RDefMap;
     // map: statement -> (map: dst reg -> src reg)
     std::map<NodeId, EqualityMap> CopyMap;
     std::vector<NodeId> Copies;
