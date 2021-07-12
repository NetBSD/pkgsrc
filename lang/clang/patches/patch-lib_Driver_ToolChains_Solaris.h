$NetBSD: patch-lib_Driver_ToolChains_Solaris.h,v 1.4 2021/07/12 18:42:06 adam Exp $

Override AddCXXStdlibLibArgs().

--- lib/Driver/ToolChains/Solaris.h.orig	2021-04-06 16:38:18.000000000 +0000
+++ lib/Driver/ToolChains/Solaris.h
@@ -59,11 +59,17 @@ public:
                             llvm::opt::ArgStringList &CC1Args) const override;
 
   void
+  addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
+                        llvm::opt::ArgStringList &CC1Args) const override;
+  void
   addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                            llvm::opt::ArgStringList &CC1Args) const override;
 
   SanitizerMask getSupportedSanitizers() const override;
   unsigned GetDefaultDwarfVersion() const override { return 2; }
+  void AddCXXStdlibLibArgs(
+     const llvm::opt::ArgList &Args,
+     llvm::opt::ArgStringList &CmdArgs) const override;
 
   const char *getDefaultLinker() const override {
     // clang currently uses Solaris ld-only options.
