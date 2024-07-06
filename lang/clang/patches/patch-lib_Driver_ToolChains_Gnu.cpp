$NetBSD: patch-lib_Driver_ToolChains_Gnu.cpp,v 1.2 2024/07/06 15:45:07 adam Exp $

On SunOS always use the GCC that was used to build clang.
Support x86_64-sun-solaris2.11 target.

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
@@ -2583,7 +2588,7 @@ void Generic_GCC::GCCInstallationDetecto
     static const char *const SolarisSparcV9Triples[] = {
         "sparcv9-sun-solaris2.11"};
     static const char *const SolarisX86Triples[] = {"i386-pc-solaris2.11"};
-    static const char *const SolarisX86_64Triples[] = {"x86_64-pc-solaris2.11"};
+    static const char *const SolarisX86_64Triples[] = {"x86_64-pc-solaris2.11", "x86_64-sun-solaris2.11"};
     LibDirs.append(begin(SolarisLibDirs), end(SolarisLibDirs));
     BiarchLibDirs.append(begin(SolarisLibDirs), end(SolarisLibDirs));
     switch (TargetTriple.getArch()) {
