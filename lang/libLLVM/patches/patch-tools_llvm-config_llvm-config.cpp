$NetBSD: patch-tools_llvm-config_llvm-config.cpp,v 1.7 2022/03/13 15:22:32 tnn Exp $

Avoid conflict with lang/clang.
Use -lLLVM-3.8 instead of -lLLVM-3.8.0 so we don't break unnecessarily
on patch updates.

--- tools/llvm-config/llvm-config.cpp.orig	2021-06-28 16:23:38.000000000 +0000
+++ tools/llvm-config/llvm-config.cpp
@@ -357,11 +357,11 @@ int main(int argc, char **argv) {
         ("-I" + ActiveIncludeDir + " " + "-I" + ActiveObjRoot + "/include");
   } else {
     ActivePrefix = CurrentExecPrefix;
-    ActiveIncludeDir = ActivePrefix + "/include";
+    ActiveIncludeDir = "@PREFIX@/include/libLLVM";
     SmallString<256> path(StringRef(LLVM_TOOLS_INSTALL_DIR));
     sys::fs::make_absolute(ActivePrefix, path);
     ActiveBinDir = std::string(path.str());
-    ActiveLibDir = ActivePrefix + "/lib" + LLVM_LIBDIR_SUFFIX;
+    ActiveLibDir = "@PREFIX@/lib/libLLVM";
     ActiveCMakeDir = ActiveLibDir + "/cmake/llvm";
     ActiveIncludeOption = "-I" + ActiveIncludeDir;
   }
@@ -399,14 +399,14 @@ int main(int argc, char **argv) {
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
@@ -419,7 +419,7 @@ int main(int argc, char **argv) {
 
   bool DyLibExists = false;
   const std::string DyLibName =
-      (SharedPrefix + "LLVM-" + SharedVersionedExt).str();
+      (SharedPrefix + "LLVM" + SharedVersionedExt).str();
 
   // If LLVM_LINK_DYLIB is ON, the single shared library will be returned
   // for "--libs", etc, if they exist. This behaviour can be overridden with
@@ -520,7 +520,7 @@ int main(int argc, char **argv) {
         OS << ActiveIncludeOption << ' ' << LLVM_CXXFLAGS << '\n';
       } else if (Arg == "--ldflags") {
         OS << ((HostTriple.isWindowsMSVCEnvironment()) ? "-LIBPATH:" : "-L")
-           << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
+           << ActiveLibDir << " @COMPILER_RPATH_FLAG@" << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
       } else if (Arg == "--system-libs") {
         PrintSystemLibs = true;
       } else if (Arg == "--libs") {
