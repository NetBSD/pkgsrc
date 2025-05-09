$NetBSD: patch-lib_llvmopencl_DebugHelpers.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/DebugHelpers.cc.orig	2025-05-03 06:32:07.508288902 +0000
+++ lib/llvmopencl/DebugHelpers.cc
@@ -82,13 +82,13 @@ static void printBasicBlock(
   s << ",label=\"" << b->getName().str() << ":\\n";

   // The work-item loop control structures.
-  if (b->getName().startswith("pregion_for_cond")) {
+  if (b->getName().starts_with("pregion_for_cond")) {
     s << "wi-loop branch\\n";
-  } else if (b->getName().startswith("pregion_for_inc")) {
+  } else if (b->getName().starts_with("pregion_for_inc")) {
     s << "local_id_* increment\\n";
-  } else if (b->getName().startswith("pregion_for_init")) {
+  } else if (b->getName().starts_with("pregion_for_init")) {
     s << "wi-loop init\\n";
-  } else if (b->getName().startswith("pregion_for_end")) {
+  } else if (b->getName().starts_with("pregion_for_end")) {
     s << "wi-loop exit\\n";
   } else {
     // analyze the contents of the BB
