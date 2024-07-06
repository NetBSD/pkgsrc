$NetBSD: patch-lib_Driver_ToolChains_Solaris.h,v 1.6 2024/07/06 15:46:46 adam Exp $

Override AddCXXStdlibLibArgs().

--- lib/Driver/ToolChains/Solaris.h.orig	2024-04-17 00:21:15.000000000 +0000
+++ lib/Driver/ToolChains/Solaris.h
@@ -61,10 +61,16 @@ public:
                             llvm::opt::ArgStringList &CC1Args) const override;
 
   void
+  addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
+                        llvm::opt::ArgStringList &CC1Args) const override;
+  void
   addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                            llvm::opt::ArgStringList &CC1Args) const override;
 
   SanitizerMask getSupportedSanitizers() const override;
+  void AddCXXStdlibLibArgs(
+     const llvm::opt::ArgList &Args,
+     llvm::opt::ArgStringList &CmdArgs) const override;
 
   const char *getDefaultLinker() const override;
 
