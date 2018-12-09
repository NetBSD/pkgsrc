$NetBSD: patch-lib_Driver_ToolChains_Solaris.cpp,v 1.2 2018/12/09 20:04:38 adam Exp $

Use compiler-rt instead of libgcc.
Pull in libcxx correctly.
Specify paths to system objects explicitly.
Don't specify --dynamic-linker, makes it impossible for the user to use -Wl,-r
Ensure we reset to -zdefaultextract prior to adding compiler-rt.
Test removing -Bdynamic for golang.

--- lib/Driver/ToolChains/Solaris.cpp.orig	2018-02-06 13:21:12.000000000 +0000
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
 
@@ -63,13 +84,8 @@ void solaris::Linker::ConstructJob(Compi
     CmdArgs.push_back("-Bstatic");
     CmdArgs.push_back("-dn");
   } else {
-    CmdArgs.push_back("-Bdynamic");
     if (Args.hasArg(options::OPT_shared)) {
       CmdArgs.push_back("-shared");
-    } else {
-      CmdArgs.push_back("--dynamic-linker");
-      CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("ld.so.1")));
     }
 
     // libpthread has been folded into libc since Solaris 10, no need to do
@@ -88,13 +104,11 @@ void solaris::Linker::ConstructJob(Compi
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     if (!Args.hasArg(options::OPT_shared))
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crt1.o")));
+          Args.MakeArgString(SysPath + "crt1.o"));
 
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
-    CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("values-Xa.o")));
+    CmdArgs.push_back(Args.MakeArgString(SysPath + "crti.o"));
     CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
+        Args.MakeArgString(SysPath + "values-Xa.o"));
   }
 
   // Provide __start___sancov_guards.  Solaris ld doesn't automatically create
@@ -113,21 +127,18 @@ void solaris::Linker::ConstructJob(Compi
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
@@ -139,11 +150,7 @@ void solaris::Linker::ConstructJob(Compi
       getToolChain().getCompilerRTArgString(Args, "sancov_end", false));
   CmdArgs.push_back("--no-whole-archive");
 
-  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
-    CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
-  }
-  CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+  CmdArgs.push_back(Args.MakeArgString(SysPath + "crtn.o"));
 
   getToolChain().addProfileRTLibs(Args, CmdArgs);
 
@@ -172,26 +179,9 @@ Solaris::Solaris(const Driver &D, const 
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
@@ -211,6 +201,32 @@ Tool *Solaris::buildAssembler() const {
 
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
