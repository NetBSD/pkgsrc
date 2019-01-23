$NetBSD: patch-lib_Driver_ToolChains_Solaris.h,v 1.3 2019/01/23 15:44:34 jperkin Exp $

Override AddCXXStdlibLibArgs().

--- lib/Driver/ToolChains/Solaris.h.orig	2018-02-05 23:59:13.000000000 +0000
+++ lib/Driver/ToolChains/Solaris.h
@@ -62,11 +62,17 @@ public:
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
 
 protected:
   Tool *buildAssembler() const override;
