$NetBSD: patch-lib_Driver_ToolChains_Gnu.cpp,v 1.4 2024/07/07 14:00:21 wiz Exp $

On SunOS always use the GCC that was used to build clang.

--- lib/Driver/ToolChains/Gnu.cpp.orig	2024-06-15 17:21:32.000000000 +0000
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -2382,6 +2382,11 @@ void Generic_GCC::GCCInstallationDetecto
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
