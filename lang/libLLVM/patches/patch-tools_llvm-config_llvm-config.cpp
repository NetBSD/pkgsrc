$NetBSD: patch-tools_llvm-config_llvm-config.cpp,v 1.1 2016/03/17 02:53:59 tnn Exp $

avoid conflict with lang/clang.
Use -lLLVM-3.8 instead of -lLLVM-3.8.0 so we don't break unnecessarily
on patch updates.

--- tools/llvm-config/llvm-config.cpp.orig	2016-01-12 07:23:58.000000000 +0000
+++ tools/llvm-config/llvm-config.cpp
@@ -309,9 +309,9 @@ int main(int argc, char **argv) {
                            "-I" + ActiveObjRoot + "/include");
   } else {
     ActivePrefix = CurrentExecPrefix;
-    ActiveIncludeDir = ActivePrefix + "/include";
+    ActiveIncludeDir = "@PREFIX@/include/libLLVM";
     ActiveBinDir = ActivePrefix + "/bin";
-    ActiveLibDir = ActivePrefix + "/lib" + LLVM_LIBDIR_SUFFIX;
+    ActiveLibDir = "@PREFIX@/lib/libLLVM";
     ActiveIncludeOption = "-I" + ActiveIncludeDir;
   }
 
@@ -334,14 +334,14 @@ int main(int argc, char **argv) {
     StaticPrefix = SharedPrefix = "lib";
   } else if (HostTriple.isOSDarwin()) {
     SharedExt = "dylib";
-    SharedVersionedExt = PACKAGE_VERSION ".dylib";
+    SharedVersionedExt = ".dylib";
     StaticExt = "a";
     StaticDir = SharedDir = ActiveLibDir;
     StaticPrefix = SharedPrefix = "lib";
   } else {
     // default to the unix values:
     SharedExt = "so";
-    SharedVersionedExt = PACKAGE_VERSION ".so";
+    SharedVersionedExt = "-@LLVM_MAJOR_MINOR@.so";
     StaticExt = "a";
     StaticDir = SharedDir = ActiveLibDir;
     StaticPrefix = SharedPrefix = "lib";
@@ -362,7 +362,7 @@ int main(int argc, char **argv) {
 
   bool DyLibExists = false;
   const std::string DyLibName =
-    (SharedPrefix + "LLVM-" + SharedVersionedExt).str();
+    (SharedPrefix + "LLVM" + SharedVersionedExt).str();
 
   if (BuiltDyLib) {
     DyLibExists = sys::fs::exists(SharedDir + "/" + DyLibName);
@@ -440,7 +440,7 @@ int main(int argc, char **argv) {
       } else if (Arg == "--cxxflags") {
         OS << ActiveIncludeOption << ' ' << LLVM_CXXFLAGS << '\n';
       } else if (Arg == "--ldflags") {
-        OS << "-L" << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
+        OS << "-L" << ActiveLibDir << " @COMPILER_RPATH_FLAG@" << ActiveLibDir << ' ' << LLVM_LDFLAGS << '\n';
       } else if (Arg == "--system-libs") {
         PrintSystemLibs = true;
       } else if (Arg == "--libs") {
