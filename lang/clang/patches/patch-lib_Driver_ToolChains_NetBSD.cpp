$NetBSD: patch-lib_Driver_ToolChains_NetBSD.cpp,v 1.1 2019/10/21 11:14:44 rjs Exp $

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2019-01-30 19:13:49.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -469,10 +469,20 @@ SanitizerMask NetBSD::getSupportedSaniti
   return Res;
 }
 
-void NetBSD::addClangTargetOptions(const ArgList &,
+void NetBSD::addClangTargetOptions(const ArgList &DriverArgs,
                                    ArgStringList &CC1Args,
                                    Action::OffloadKind) const {
   const SanitizerArgs &SanArgs = getSanitizerArgs();
+  bool UseInitArrayDefault =
+      getTriple().getArch() == llvm::Triple::aarch64 ||
+      getTriple().getArch() == llvm::Triple::aarch64_be ||
+      getTriple().getArch() == llvm::Triple::riscv32 ||
+      getTriple().getArch() == llvm::Triple::riscv64;
+
+  if (DriverArgs.hasFlag(options::OPT_fuse_init_array,
+                         options::OPT_fno_use_init_array, UseInitArrayDefault))
+    CC1Args.push_back("-fuse-init-array");
+
   if (SanArgs.hasAnySanitizer())
     CC1Args.push_back("-D_REENTRANT");
 }
