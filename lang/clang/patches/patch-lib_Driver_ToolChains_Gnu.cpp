$NetBSD: patch-lib_Driver_ToolChains_Gnu.cpp,v 1.1 2024/05/09 14:15:51 jperkin Exp $

On SunOS always use the GCC that was used to build clang.
Support x86_64-sun-solaris2.11 target.

--- lib/Driver/ToolChains/Gnu.cpp.orig	2024-05-09 10:06:41.859223500 +0000
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -2228,6 +2228,11 @@ void Generic_GCC::GCCInstallationDetecto
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
@@ -2431,6 +2436,7 @@ void Generic_GCC::GCCInstallationDetecto
     static const char *const SolarisX86Triples[] = {"i386-pc-solaris2.11",
                                                     "i386-pc-solaris2.12"};
     static const char *const SolarisX86_64Triples[] = {"x86_64-pc-solaris2.11",
+                                                       "x86_64-sun-solaris2.11",
                                                        "x86_64-pc-solaris2.12"};
     LibDirs.append(begin(SolarisLibDirs), end(SolarisLibDirs));
     BiarchLibDirs.append(begin(SolarisLibDirs), end(SolarisLibDirs));
