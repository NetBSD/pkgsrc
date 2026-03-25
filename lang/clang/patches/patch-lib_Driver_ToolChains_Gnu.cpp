$NetBSD: patch-lib_Driver_ToolChains_Gnu.cpp,v 1.5 2026/03/25 22:56:25 wiz Exp $

On SunOS always use the GCC that was used to build clang.

--- lib/Driver/ToolChains/Gnu.cpp.orig	2026-02-21 07:22:27.510926289 +0000
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -2348,6 +2348,11 @@ void Generic_GCC::GCCInstallationDetector::AddDefaultG
     // /usr/gcc/<version> as a prefix.
 
     SmallVector<std::pair<GCCVersion, std::string>, 8> SolarisPrefixes;
+
+    // Only use compiler as configured by pkgsrc
+    Prefixes.push_back("@GCCBASEDIR@");
+    return;
+
     std::string PrefixDir = concat(SysRoot, "/usr/gcc");
     std::error_code EC;
     for (llvm::vfs::directory_iterator LI = D.getVFS().dir_begin(PrefixDir, EC),
