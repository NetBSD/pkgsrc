$NetBSD: patch-tools_llvm-config_llvm-config.cpp,v 1.3 2017/03/17 22:38:18 adam Exp $

Avoid conflict with lang/clang.
Use -lLLVM-3.8 instead of -lLLVM-3.8.0 so we don't break unnecessarily
on patch updates.

--- tools/llvm-config/llvm-config.cpp.orig	2017-01-12 19:47:38.000000000 +0000
+++ tools/llvm-config/llvm-config.cpp
@@ -332,9 +332,9 @@ int main(int argc, char **argv) {
         ("-I" + ActiveIncludeDir + " " + "-I" + ActiveObjRoot + "/include");
   } else {
     ActivePrefix = CurrentExecPrefix;
-    ActiveIncludeDir = ActivePrefix + "/include";
+    ActiveIncludeDir = "@PREFIX@/include/libLLVM";
     ActiveBinDir = ActivePrefix + "/bin";
-    ActiveLibDir = ActivePrefix + "/lib" + LLVM_LIBDIR_SUFFIX;
+    ActiveLibDir = "@PREFIX@/lib/libLLVM";
     ActiveCMakeDir = ActiveLibDir + "/cmake/llvm";
     ActiveIncludeOption = "-I" + ActiveIncludeDir;
   }
@@ -370,14 +370,14 @@ int main(int argc, char **argv) {
     StaticDir = ActiveLibDir;
   } else if (HostTriple.isOSDarwin()) {
     SharedExt = "dylib";
-    SharedVersionedExt = LLVM_DYLIB_VERSION ".dylib";
+    SharedVersionedExt = ".dylib";
     StaticExt = "a";
     StaticDir = SharedDir = ActiveLibDir;
     StaticPrefix = SharedPrefix = "lib";
   } else {
     // default to the unix values:
     SharedExt = "so";
-    SharedVersionedExt = LLVM_DYLIB_VERSION ".so";
+    SharedVersionedExt = "-@LLVM_MAJOR_MINOR@.so";
     StaticExt = "a";
     StaticDir = SharedDir = ActiveLibDir;
     StaticPrefix = SharedPrefix = "lib";
@@ -390,7 +390,7 @@ int main(int argc, char **argv) {
 
   bool DyLibExists = false;
   const std::string DyLibName =
-      (SharedPrefix + "LLVM-" + SharedVersionedExt).str();
+      (SharedPrefix + "LLVM" + SharedVersionedExt).str();
 
   // If LLVM_LINK_DYLIB is ON, the single shared library will be returned
   // for "--libs", etc, if they exist. This behaviour can be overridden with
@@ -491,7 +491,7 @@ int main(int argc, char **argv) {
         OS << ActiveIncludeOption << ' ' << LLVM_CXXFLAGS << '\n';
       } else if (Arg == "--ldflags") {
         OS << ((HostTriple.isWindowsMSVCEnvironment()) ? "-LIBPATH:" : "-L")
-           << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
+           << ActiveLibDir << " @COMPILER_RPATH_FLAG@" << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
       } else if (Arg == "--system-libs") {
         PrintSystemLibs = true;
       } else if (Arg == "--libs") {
