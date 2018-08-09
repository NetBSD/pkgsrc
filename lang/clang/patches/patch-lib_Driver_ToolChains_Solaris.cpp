$NetBSD: patch-lib_Driver_ToolChains_Solaris.cpp,v 1.1 2018/08/09 14:56:41 jperkin Exp $

Use compiler-rt instead of libgcc.
Pull in libcxx correctly.
Specify paths to system objects explicitly.
Don't specify --dynamic-linker, makes it impossible for the user to use -Wl,-r
Ensure we reset to -zdefaultextract prior to adding compiler-rt.
Test removing -Bdynamic for golang.

--- lib/Driver/ToolChains/Solaris.cpp.orig	2018-01-04 07:43:41.000000000 +0000
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
 
@@ -62,15 +83,8 @@ void solaris::Linker::ConstructJob(Compi
   if (Args.hasArg(options::OPT_static)) {
     CmdArgs.push_back("-Bstatic");
     CmdArgs.push_back("-dn");
-  } else {
-    CmdArgs.push_back("-Bdynamic");
-    if (Args.hasArg(options::OPT_shared)) {
-      CmdArgs.push_back("-shared");
-    } else {
-      CmdArgs.push_back("--dynamic-linker");
-      CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("ld.so.1")));
-    }
+  } else if (Args.hasArg(options::OPT_shared)) {
+    CmdArgs.push_back("-shared");
   }
 
   if (Output.isFilename()) {
@@ -83,13 +97,11 @@ void solaris::Linker::ConstructJob(Compi
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
 
   getToolChain().AddFilePathLibArgs(Args, CmdArgs);
@@ -100,21 +112,21 @@ void solaris::Linker::ConstructJob(Compi
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
-    if (getToolChain().ShouldLinkCXXStdlib(Args))
-      getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
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
   }
 
-  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
-    CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
-  }
-  CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+  CmdArgs.push_back(Args.MakeArgString(SysPath + "crtn.o"));
 
   getToolChain().addProfileRTLibs(Args, CmdArgs);
 
@@ -127,35 +139,9 @@ void solaris::Linker::ConstructJob(Compi
 Solaris::Solaris(const Driver &D, const llvm::Triple &Triple,
                  const ArgList &Args)
     : Generic_ELF(D, Triple, Args) {
-
-  GCCInstallation.init(Triple, Args);
-
-  path_list &Paths = getFilePaths();
-  if (GCCInstallation.isValid())
-    addPathIfExists(D, GCCInstallation.getInstallPath(), Paths);
-
-  addPathIfExists(D, getDriver().getInstalledDir(), Paths);
-  if (getDriver().getInstalledDir() != getDriver().Dir)
-    addPathIfExists(D, getDriver().Dir, Paths);
-
-  addPathIfExists(D, getDriver().SysRoot + getDriver().Dir + "/../lib", Paths);
-
-  std::string LibPath = "/usr/lib/";
-  switch (Triple.getArch()) {
-  case llvm::Triple::x86:
-  case llvm::Triple::sparc:
-    break;
-  case llvm::Triple::x86_64:
-    LibPath += "amd64/";
-    break;
-  case llvm::Triple::sparcv9:
-    LibPath += "sparcv9/";
-    break;
-  default:
-    llvm_unreachable("Unsupported architecture");
-  }
-
-  addPathIfExists(D, getDriver().SysRoot + LibPath, Paths);
+  // No special handling, the C runtime files are found directly above
+  // and crle handles adding the default system library paths if they
+  // are necessary.
 }
 
 Tool *Solaris::buildAssembler() const {
@@ -164,30 +150,41 @@ Tool *Solaris::buildAssembler() const {
 
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
 void Solaris::AddClangCXXStdlibIncludeArgs(const ArgList &DriverArgs,
                                            ArgStringList &CC1Args) const {
   if (DriverArgs.hasArg(options::OPT_nostdlibinc) ||
       DriverArgs.hasArg(options::OPT_nostdincxx))
     return;
 
-  // Include the support directory for things like xlocale and fudged system
-  // headers.
-  // FIXME: This is a weird mix of libc++ and libstdc++. We should also be
-  // checking the value of -stdlib= here and adding the includes for libc++
-  // rather than libstdc++ if it's requested.
-  addSystemInclude(DriverArgs, CC1Args, "/usr/include/c++/v1/support/solaris");
-
-  if (GCCInstallation.isValid()) {
-    GCCVersion Version = GCCInstallation.getVersion();
-    addSystemInclude(DriverArgs, CC1Args,
-                     getDriver().SysRoot + "/usr/gcc/" +
-                     Version.MajorStr + "." +
-                     Version.MinorStr +
-                     "/include/c++/" + Version.Text);
-    addSystemInclude(DriverArgs, CC1Args,
-                     getDriver().SysRoot + "/usr/gcc/" + Version.MajorStr +
-                     "." + Version.MinorStr + "/include/c++/" +
-                     Version.Text + "/" +
-                     GCCInstallation.getTriple().str());
-  }
+  // Currently assumes pkgsrc layout.
+  addSystemInclude(DriverArgs, CC1Args,
+                   llvm::sys::path::parent_path(getDriver().getInstalledDir())
+                   + "/include/c++/v1");
+  return;
 }
