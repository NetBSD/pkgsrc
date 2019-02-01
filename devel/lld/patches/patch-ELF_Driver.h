$NetBSD: patch-ELF_Driver.h,v 1.1 2019/02/01 16:30:00 mgorny Exp $

Add support for customizing LLD behavior on target triple.
https://reviews.llvm.org/D56650

Alter defaults for NetBSD targets:
* add default library search paths

--- ELF/Driver.h.orig	2018-07-25 21:53:18.000000000 +0000
+++ ELF/Driver.h
@@ -31,7 +31,9 @@ public:
   void addLibrary(StringRef Name);
 
 private:
+  void setTargetTriple(StringRef argv0, llvm::opt::InputArgList &Args);
   void readConfigs(llvm::opt::InputArgList &Args);
+  void appendDefaultSearchPaths();
   void createFiles(llvm::opt::InputArgList &Args);
   void inferMachineType();
   template <class ELFT> void link(llvm::opt::InputArgList &Args);
