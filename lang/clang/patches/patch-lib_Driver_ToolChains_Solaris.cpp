$NetBSD: patch-lib_Driver_ToolChains_Solaris.cpp,v 1.6 2020/06/05 15:28:54 jperkin Exp $

Use compiler-rt instead of libgcc.
Pull in libcxx correctly.
Specify paths to system objects explicitly.
Don't specify --dynamic-linker, makes it impossible for the user to use -Wl,-r
Ensure we reset to -zdefaultextract prior to adding compiler-rt.
Test removing -Bdynamic for golang.

--- lib/Driver/ToolChains/Solaris.cpp.orig	2020-03-23 15:01:02.000000000 +0000
+++ lib/Driver/ToolChains/Solaris.cpp
@@ -49,8 +49,29 @@ void solaris::Linker::ConstructJob(Compi
                                    const InputInfoList &Inputs,
                                    const ArgList &Args,
                                    const char *LinkingOutput) const {
+  const Driver &D = getToolChain().getDriver();
   ArgStringList CmdArgs;
 
+  // XXX: assumes pkgsrc layout
+  std::string LibPath;
+  LibPath = llvm::sys::path::parent_path(D.getInstalledDir());
+  LibPath += "/lib/";
+
+  std::string SysPath = "/usr/lib/";
+  switch (getToolChain().getArch()) {
+  case llvm::Triple::x86:
+  case llvm::Triple::sparc:
+    break;
+  case llvm::Triple::x86_64:
+    SysPath += "amd64/";
+    break;
+  case llvm::Triple::sparcv9:
+    SysPath += "sparcv9/";
+    break;
+  default:
+    llvm_unreachable("Unsupported architecture");
+  }
+
   // Demangle C++ names in errors
   CmdArgs.push_back("-C");
 
@@ -63,7 +84,6 @@ void solaris::Linker::ConstructJob(Compi
     CmdArgs.push_back("-Bstatic");
     CmdArgs.push_back("-dn");
   } else {
-    CmdArgs.push_back("-Bdynamic");
     if (Args.hasArg(options::OPT_shared)) {
       CmdArgs.push_back("-shared");
     }
@@ -84,9 +104,9 @@ void solaris::Linker::ConstructJob(Compi
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     if (!Args.hasArg(options::OPT_shared))
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
+          Args.MakeArgString(SysPath + "crt1.o"));
 
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
+    CmdArgs.push_back(Args.MakeArgString(SysPath + "crti.o"));
 
     const Arg *Std = Args.getLastArg(options::OPT_std_EQ, options::OPT_ansi);
     bool HaveAnsi = false;
@@ -101,16 +121,14 @@ void solaris::Linker::ConstructJob(Compi
     // Use values-Xc.o for -ansi, -std=c*, -std=iso9899:199409.
     if (HaveAnsi || (LangStd && !LangStd->isGNUMode()))
       values_X = "values-Xc.o";
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(values_X)));
+    CmdArgs.push_back(Args.MakeArgString(SysPath + values_X));
 
     const char *values_xpg = "values-xpg6.o";
     // Use values-xpg4.o for -std=c90, -std=gnu90, -std=iso9899:199409.
     if (LangStd && LangStd->getLanguage() == Language::C && !LangStd->isC99())
       values_xpg = "values-xpg4.o";
     CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath(values_xpg)));
-    CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
+        Args.MakeArgString(SysPath + values_xpg));
   }
 
   getToolChain().AddFilePathLibArgs(Args, CmdArgs);
@@ -122,30 +140,23 @@ void solaris::Linker::ConstructJob(Compi
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
-    if (getToolChain().ShouldLinkCXXStdlib(Args))
-      getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
-    if (Args.hasArg(options::OPT_fstack_protector) ||
-        Args.hasArg(options::OPT_fstack_protector_strong) ||
-        Args.hasArg(options::OPT_fstack_protector_all)) {
-      // Explicitly link ssp libraries, not folded into Solaris libc.
-      CmdArgs.push_back("-lssp_nonshared");
-      CmdArgs.push_back("-lssp");
-    }
-    CmdArgs.push_back("-lgcc_s");
-    CmdArgs.push_back("-lc");
-    if (!Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back("-lgcc");
+    // This specifically uses -Wl to avoid CMake parsing it and trying to
+    // feed "-zdefaultextract" back into clang, which doesn't support the
+    // non-space version.
+    CmdArgs.push_back("-Wl,-zdefaultextract");
+    AddRunTimeLibs(getToolChain(), D, CmdArgs, Args);
+    CmdArgs.push_back(Args.MakeArgString(LibPath + "libunwind.a"));
+    if (D.CCCIsCXX()) {
+      if (getToolChain().ShouldLinkCXXStdlib(Args))
+        getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
       CmdArgs.push_back("-lm");
     }
+    CmdArgs.push_back("-lc");
     if (NeedsSanitizerDeps)
       linkSanitizerRuntimeDeps(getToolChain(), CmdArgs);
   }
 
-  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
-    CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
-  }
-  CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+  CmdArgs.push_back(Args.MakeArgString(SysPath + "crtn.o"));
 
   getToolChain().addProfileRTLibs(Args, CmdArgs);
 
@@ -174,26 +185,9 @@ Solaris::Solaris(const Driver &D, const 
                  const ArgList &Args)
     : Generic_ELF(D, Triple, Args) {
 
-  GCCInstallation.init(Triple, Args);
-
-  StringRef LibSuffix = getSolarisLibSuffix(Triple);
-  path_list &Paths = getFilePaths();
-  if (GCCInstallation.isValid()) {
-    // On Solaris gcc uses both an architecture-specific path with triple in it
-    // as well as a more generic lib path (+arch suffix).
-    addPathIfExists(D,
-                    GCCInstallation.getInstallPath() +
-                        GCCInstallation.getMultilib().gccSuffix(),
-                    Paths);
-    addPathIfExists(D, GCCInstallation.getParentLibPath() + LibSuffix, Paths);
-  }
-
-  // If we are currently running Clang inside of the requested system root,
-  // add its parent library path to those searched.
-  if (StringRef(D.Dir).startswith(D.SysRoot))
-    addPathIfExists(D, D.Dir + "/../lib", Paths);
-
-  addPathIfExists(D, D.SysRoot + "/usr/lib" + LibSuffix, Paths);
+  // No special handling, the C runtime files are found directly above
+  // and crle handles adding the default system library paths if they
+  // are necessary.
 }
 
 SanitizerMask Solaris::getSupportedSanitizers() const {
@@ -218,6 +212,32 @@ Tool *Solaris::buildAssembler() const {
 
 Tool *Solaris::buildLinker() const { return new tools::solaris::Linker(*this); }
 
+void Solaris::AddCXXStdlibLibArgs(const ArgList &Args,
+                                  ArgStringList &CmdArgs) const {
+  CXXStdlibType Type = GetCXXStdlibType(Args);
+
+  // Currently assumes pkgsrc layout where libcxx and libcxxabi are installed
+  // in the same prefixed directory that we are.
+  std::string LibPath;
+  LibPath = llvm::sys::path::parent_path(getDriver().getInstalledDir());
+  LibPath += "/lib";
+
+  switch (Type) {
+  case ToolChain::CST_Libcxx:
+    CmdArgs.push_back(Args.MakeArgString(StringRef("-L") + LibPath));
+    CmdArgs.push_back(Args.MakeArgString(StringRef("-R") + LibPath));
+    CmdArgs.push_back("-lc++");
+    CmdArgs.push_back("-lc++abi");
+    break;
+
+  // XXX: This won't work without being told exactly where libstdc++ is, but
+  // that changes based on distribution.  Maybe return ENOTSUP here?
+  case ToolChain::CST_Libstdcxx:
+    CmdArgs.push_back("-lstdc++");
+    break;
+  }
+}
+
 void Solaris::AddClangSystemIncludeArgs(const ArgList &DriverArgs,
                                         ArgStringList &CC1Args) const {
   const Driver &D = getDriver();
@@ -250,40 +270,20 @@ void Solaris::AddClangSystemIncludeArgs(
     return;
   }
 
-  // Add include directories specific to the selected multilib set and multilib.
-  if (GCCInstallation.isValid()) {
-    const MultilibSet::IncludeDirsFunc &Callback =
-        Multilibs.includeDirsCallback();
-    if (Callback) {
-      for (const auto &Path : Callback(GCCInstallation.getMultilib()))
-        addExternCSystemIncludeIfExists(
-            DriverArgs, CC1Args, GCCInstallation.getInstallPath() + Path);
-    }
-  }
-
   addExternCSystemInclude(DriverArgs, CC1Args, D.SysRoot + "/usr/include");
 }
 
-void Solaris::addLibStdCxxIncludePaths(
+void Solaris::addLibCxxIncludePaths(
     const llvm::opt::ArgList &DriverArgs,
     llvm::opt::ArgStringList &CC1Args) const {
-  // We need a detected GCC installation on Solaris (similar to Linux)
-  // to provide libstdc++'s headers.
-  if (!GCCInstallation.isValid())
-    return;
+  addSystemInclude(DriverArgs, CC1Args,
+                   llvm::sys::path::parent_path(getDriver().getInstalledDir())
+                   + "/include/c++/v1");
+}
 
-  // By default, look for the C++ headers in an include directory adjacent to
-  // the lib directory of the GCC installation.
-  // On Solaris this usually looks like /usr/gcc/X.Y/include/c++/X.Y.Z
-  StringRef LibDir = GCCInstallation.getParentLibPath();
-  StringRef TripleStr = GCCInstallation.getTriple().str();
-  const Multilib &Multilib = GCCInstallation.getMultilib();
-  const GCCVersion &Version = GCCInstallation.getVersion();
-
-  // The primary search for libstdc++ supports multiarch variants.
-  addLibStdCXXIncludePaths(LibDir.str() + "/../include", "/c++/" + Version.Text,
-                           TripleStr,
-                           /*GCCMultiarchTriple*/ "",
-                           /*TargetMultiarchTriple*/ "",
-                           Multilib.includeSuffix(), DriverArgs, CC1Args);
+void Solaris::addLibStdCxxIncludePaths(
+    const llvm::opt::ArgList &DriverArgs,
+    llvm::opt::ArgStringList &CC1Args) const {
+  // Location of GCC includes is not reliable so do not support it.
+  return;
 }
