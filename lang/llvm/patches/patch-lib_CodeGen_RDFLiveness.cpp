$NetBSD: patch-lib_CodeGen_RDFLiveness.cpp,v 1.1 2026/09/15 21:10:07 tnn Exp $

https://github.com/llvm/llvm-project/commit/a558d656043734cc4d02e0a0a12e4c308c28f8c7.patch

--- lib/CodeGen/RDFLiveness.cpp.orig	2025-12-12 10:35:47.000000000 +0000
+++ lib/CodeGen/RDFLiveness.cpp
@@ -652,8 +652,9 @@ void Liveness::computePhiInfo() {
   // defs, cache the result of subtracting these defs from a given register
   // ref.
   using RefHash = std::hash<RegisterRef>;
-  using RefEqual = std::equal_to<RegisterRef>;
-  using SubMap = std::unordered_map<RegisterRef, RegisterRef>;
+  using RefEqual = RegisterRefEqualTo;
+  using SubMap =
+      std::unordered_map<RegisterRef, RegisterRef, RefHash, RefEqual>;
   std::unordered_map<RegisterAggr, SubMap> Subs;
   auto ClearIn = [](RegisterRef RR, const RegisterAggr &Mid, SubMap &SM) {
     if (Mid.empty())
@@ -868,7 +869,7 @@ void Liveness::computeLiveIns() {
       std::vector<RegisterRef> LV;
       for (const MachineBasicBlock::RegisterMaskPair &LI : B.liveins())
         LV.push_back(RegisterRef(LI.PhysReg, LI.LaneMask));
-      llvm::sort(LV, std::less<RegisterRef>(PRI));
+      llvm::sort(LV, RegisterRefLess(PRI));
       dbgs() << printMBBReference(B) << "\t rec = {";
       for (auto I : LV)
         dbgs() << ' ' << Print(I, DFG);
@@ -878,7 +879,7 @@ void Liveness::computeLiveIns() {
       LV.clear();
       for (RegisterRef RR : LiveMap[&B].refs())
         LV.push_back(RR);
-      llvm::sort(LV, std::less<RegisterRef>(PRI));
+      llvm::sort(LV, RegisterRefLess(PRI));
       dbgs() << "\tcomp = {";
       for (auto I : LV)
         dbgs() << ' ' << Print(I, DFG);
