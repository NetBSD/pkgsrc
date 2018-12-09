$NetBSD: patch-lib_Driver_ToolChains_Solaris.h,v 1.2 2018/12/09 20:04:38 adam Exp $

Override AddCXXStdlibLibArgs().

--- lib/Driver/ToolChains/Solaris.h.orig	2018-02-05 23:59:13.000000000 +0000
+++ lib/Driver/ToolChains/Solaris.h
@@ -67,6 +67,9 @@ public:
 
   SanitizerMask getSupportedSanitizers() const override;
   unsigned GetDefaultDwarfVersion() const override { return 2; }
+  void AddCXXStdlibLibArgs(
+     const llvm::opt::ArgList &Args,
+     llvm::opt::ArgStringList &CmdArgs) const override;
 
 protected:
   Tool *buildAssembler() const override;
