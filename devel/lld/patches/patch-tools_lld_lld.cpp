$NetBSD: patch-tools_lld_lld.cpp,v 1.1 2019/11/03 12:11:27 kamil Exp $

[LLD] Add NetBSD support as a new flavor of LLD (nb.lld)
https://reviews.llvm.org/D69755

--- tools/lld/lld.cpp.orig	2019-07-11 06:12:18.000000000 +0000
+++ tools/lld/lld.cpp
@@ -10,12 +10,13 @@
 // function is a thin wrapper which dispatches to the platform specific
 // driver.
 //
-// lld is a single executable that contains four different linkers for ELF,
-// COFF, WebAssembly and Mach-O. The main function dispatches according to
-// argv[0] (i.e. command name). The most common name for each target is shown
+// lld is a single executable that contains five different linkers for ELF,
+// NetBSD, COFF, WebAssembly and Mach-O. The main function dispatches according
+// to argv[0] (i.e. command name). The most common name for each target is shown
 // below:
 //
 //  - ld.lld:    ELF (Unix)
+//  - nb.lld:    ELF (NetBSD)
 //  - ld64:      Mach-O (macOS)
 //  - lld-link:  COFF (Windows)
 //  - ld-wasm:   WebAssembly
@@ -35,6 +36,9 @@
 #include "llvm/Support/CommandLine.h"
 #include "llvm/Support/InitLLVM.h"
 #include "llvm/Support/Path.h"
+#include "llvm/Support/Program.h"
+#include "llvm/Support/WithColor.h"
+#include "llvm/Support/raw_ostream.h"
 #include <cstdlib>
 
 using namespace lld;
@@ -44,6 +48,7 @@ using namespace llvm::sys;
 enum Flavor {
   Invalid,
   Gnu,     // -flavor gnu
+  NetBSD,  // -flavor netbsd
   WinLink, // -flavor link
   Darwin,  // -flavor darwin
   Wasm,    // -flavor wasm
@@ -57,6 +62,7 @@ LLVM_ATTRIBUTE_NORETURN static void die(
 static Flavor getFlavor(StringRef s) {
   return StringSwitch<Flavor>(s)
       .CasesLower("ld", "ld.lld", "gnu", Gnu)
+      .CasesLower("nb.lld", "netbsd", NetBSD)
       .CasesLower("wasm", "ld-wasm", Wasm)
       .CaseLower("link", WinLink)
       .CasesLower("ld64", "ld64.lld", "darwin", Darwin)
@@ -99,10 +105,15 @@ static Flavor parseProgname(StringRef pr
 #endif
 
 #if LLVM_ON_UNIX
-  // Use GNU driver for "ld" on other Unix-like system.
-  if (progname == "ld")
+  // Use GNU or NetBSD driver for "ld" on other Unix-like system.
+  if (progname == "ld") {
+#if defined(__NetBSD__)
+    return NetBSD;
+#else
     return Gnu;
 #endif
+  }
+#endif
 
   // Progname may be something like "lld-gnu". Parse it.
   SmallVector<StringRef, 3> v;
@@ -132,6 +143,38 @@ static Flavor parseFlavor(std::vector<co
   return parseProgname(arg0);
 }
 
+// The NetBSD linker flavor will mutate arguments and call the GNU linker.
+static int exec_nb_lld(int argc, const char **argv) {
+  auto Program = sys::findProgramByName("nb.lld");
+  if (!Program) {
+    WithColor::error() << "unable to find `nb.lld' in PATH: "
+                       << Program.getError().message() << "\n";
+    return 1;
+  }
+
+  std::vector<StringRef> Argv;
+  Argv.push_back("nb.lld");
+
+  // Trim -flavor option.
+  if (argc > 1 && argv[0] == StringRef("-flavor")) {
+    if (argc <= 2)
+      die("missing arg value for '-flavor'");
+    argc -= 2;
+    argv += 2;
+  }
+
+  for (int i = 0; i < argc; ++i)
+    Argv.push_back(argv[i]);
+
+  std::string ErrMsg;
+  int Result = sys::ExecuteAndWait(*Program, Argv, None, {}, 0, 0, &ErrMsg);
+  if (Result < 0) {
+    WithColor::error() << ErrMsg << "\n";
+    return 1;
+  }
+  return Result;
+}
+
 // If this function returns true, lld calls _exit() so that it quickly
 // exits without invoking destructors of globally allocated objects.
 //
@@ -140,7 +183,7 @@ static Flavor parseFlavor(std::vector<co
 // and we use it to detect whether we are running tests or not.
 static bool canExitEarly() { return StringRef(getenv("LLD_IN_TEST")) != "1"; }
 
-/// Universal linker main(). This linker emulates the gnu, darwin, or
+/// Universal linker main(). This linker emulates the gnu, netbsd, darwin, or
 /// windows linker based on the argv[0] or -flavor option.
 int main(int argc, const char **argv) {
   InitLLVM x(argc, argv);
@@ -151,6 +194,8 @@ int main(int argc, const char **argv) {
     if (isPETarget(args))
       return !mingw::link(args);
     return !elf::link(args, canExitEarly());
+  case NetBSD:
+    return exec_nb_lld(argc - 1, argv + 1);
   case WinLink:
     return !coff::link(args, canExitEarly());
   case Darwin:
@@ -159,7 +204,8 @@ int main(int argc, const char **argv) {
     return !wasm::link(args, canExitEarly());
   default:
     die("lld is a generic driver.\n"
-        "Invoke ld.lld (Unix), ld64.lld (macOS), lld-link (Windows), wasm-ld"
+        "Invoke ld.lld (Unix), nb.lld (NetBSD), ld64.lld (macOS), lld-link "
+        "(Windows), wasm-ld"
         " (WebAssembly) instead");
   }
 }
