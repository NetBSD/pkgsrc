$NetBSD: patch-tools_nb.lld_nb.lld.cpp,v 1.2 2019/11/03 12:40:40 kamil Exp $

[LLD] Add NetBSD support as a new flavor of LLD (nb.lld)
https://reviews.llvm.org/D69755

Disable gnustack for NetBSD.

--- tools/nb.lld/nb.lld.cpp.orig	2019-11-03 12:31:14.712069007 +0000
+++ tools/nb.lld/nb.lld.cpp
@@ -0,0 +1,221 @@
+//===- nb.lld.cpp - NetBSD LLD standalone linker --------------------------===//
+//
+// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
+// See https://llvm.org/LICENSE.txt for license information.
+// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
+//
+//===----------------------------------------------------------------------===//
+//
+// The NetBSD flavor of LLD.
+//
+// This code wraps the default ELF/UNIX lld variation with NetBSD specific
+// customization.
+//
+//===----------------------------------------------------------------------===//
+
+#include "llvm/ADT/Triple.h"
+#include "llvm/Option/ArgList.h"
+#include "llvm/Option/Option.h"
+#include "llvm/Support/Host.h"
+#include "llvm/Support/InitLLVM.h"
+#include "llvm/Support/Path.h"
+#include "llvm/Support/Program.h"
+#include "llvm/Support/TargetRegistry.h"
+#include "llvm/Support/TargetSelect.h"
+#include "llvm/Support/WithColor.h"
+#include "llvm/Support/raw_ostream.h"
+
+using namespace llvm;
+using namespace llvm::sys;
+
+#define LLD_PROGNAME "ld.lld"
+
+namespace {
+enum ID {
+  OPT_INVALID = 0, // This is not an option ID.
+#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, ALIASARGS, FLAGS, PARAM,  \
+               HELPTEXT, METAVAR, VALUES)                                      \
+  OPT_##ID,
+#include "Options.inc"
+#undef OPTION
+};
+
+#define PREFIX(NAME, VALUE) const char *const NAME[] = VALUE;
+#include "Options.inc"
+#undef PREFIX
+
+const opt::OptTable::Info InfoTable[] = {
+#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, ALIASARGS, FLAGS, PARAM,  \
+               HELPTEXT, METAVAR, VALUES)                                      \
+  {                                                                            \
+      PREFIX,      NAME,      HELPTEXT,                                        \
+      METAVAR,     OPT_##ID,  opt::Option::KIND##Class,                        \
+      PARAM,       FLAGS,     OPT_##GROUP,                                     \
+      OPT_##ALIAS, ALIASARGS, VALUES},
+#include "Options.inc"
+#undef OPTION
+};
+
+class SLLDOptTable : public opt::OptTable {
+public:
+  SLLDOptTable() : OptTable(InfoTable) {}
+};
+} // namespace
+
+static Triple targetTriple;
+
+static void setTargetTriple(StringRef argv0, opt::InputArgList &args) {
+  std::string targetError;
+
+  // Firstly, try to get it from program name prefix
+  std::string ProgName = llvm::sys::path::stem(argv0);
+  size_t lastComponent = ProgName.rfind('-');
+  if (lastComponent != std::string::npos) {
+    std::string prefix = ProgName.substr(0, lastComponent);
+    if (llvm::TargetRegistry::lookupTarget(prefix, targetError)) {
+      targetTriple = llvm::Triple(prefix);
+      return;
+    }
+  }
+
+  // Secondly, use the default target triple
+  targetTriple = llvm::Triple(getDefaultTargetTriple());
+}
+
+static void appendSearchPath(std::vector<StringRef> &args, const char *path) {
+  args.push_back("--library-path");
+  args.push_back(path);
+}
+
+static void appendTargetCustomization(std::vector<StringRef> &args) {
+  // force-disable RO segment on NetBSD due to ld.elf_so limitations
+  args.push_back("--no-rosegment");
+
+  // disable superfluous RUNPATH on NetBSD
+  args.push_back("--disable-new-dtags");
+
+  // disable gnustack
+  args.push_back("-znognustack");
+
+  // set default image base address
+  switch (targetTriple.getArch()) {
+  case llvm::Triple::aarch64:
+  case llvm::Triple::aarch64_be:
+    args.push_back("--image-base=0x200100000");
+    break;
+  default:
+    break;
+  }
+
+  // NetBSD driver relies on the linker knowing the default search paths.
+  // Please keep this in sync with clang/lib/Driver/ToolChains/NetBSD.cpp
+  // (NetBSD::NetBSD constructor)
+  switch (targetTriple.getArch()) {
+  case llvm::Triple::x86:
+    appendSearchPath(args, "=/usr/lib/i386");
+    break;
+  case llvm::Triple::arm:
+  case llvm::Triple::armeb:
+  case llvm::Triple::thumb:
+  case llvm::Triple::thumbeb:
+    switch (targetTriple.getEnvironment()) {
+    case llvm::Triple::EABI:
+    case llvm::Triple::GNUEABI:
+      appendSearchPath(args, "=/usr/lib/eabi");
+      break;
+    case llvm::Triple::EABIHF:
+    case llvm::Triple::GNUEABIHF:
+      appendSearchPath(args, "=/usr/lib/eabihf");
+      break;
+    default:
+      appendSearchPath(args, "=/usr/lib/oabi");
+      break;
+    }
+    break;
+#if 0 // TODO
+  case llvm::Triple::mips64:
+  case llvm::Triple::mips64el:
+    if (tools::mips::hasMipsAbiArg(Args, "o32")) {
+      appendSearchPath(args, "=/usr/lib/o32");
+    } else if (tools::mips::hasMipsAbiArg(Args, "64")) {
+      appendSearchPath(args, "=/usr/lib/64");
+    }
+    break;
+#endif
+  case llvm::Triple::ppc:
+    appendSearchPath(args, "=/usr/lib/powerpc");
+    break;
+  case llvm::Triple::sparc:
+    appendSearchPath(args, "=/usr/lib/sparc");
+    break;
+  default:
+    break;
+  }
+
+  appendSearchPath(args, "=/usr/lib");
+}
+
+int main(int argc, const char **argv) {
+  bool printTarget = false;
+
+  InitLLVM X(argc, argv);
+
+  auto Program = sys::findProgramByName(LLD_PROGNAME);
+  if (!Program) {
+    WithColor::error() << "unable to find `" << LLD_PROGNAME
+                       << "' in PATH: " << Program.getError().message() << "\n";
+    return 1;
+  }
+
+  ArrayRef<const char *> argsArr = makeArrayRef(argv, argc);
+
+  SLLDOptTable parser;
+  unsigned MAI;
+  unsigned MAC;
+  opt::InputArgList args = parser.ParseArgs(argsArr.slice(1), MAI, MAC);
+
+  // Append to -v or -version the target information from slld.
+  if (args.hasArg(OPT_v) || args.hasArg(OPT_version))
+    printTarget = true;
+
+  InitializeAllTargets();
+  setTargetTriple(argsArr[0], args);
+
+  if (!targetTriple.isOSNetBSD()) {
+    WithColor::error() << "invalid NetBSD target: " << targetTriple.str()
+                       << "\n";
+  }
+
+  argc--;
+  argv++;
+
+  std::vector<StringRef> Argv;
+  Argv.push_back(*Program);
+
+  // Prepend original arguments with the target options.
+  appendTargetCustomization(Argv);
+
+  // Append original options.
+  // Trim -flavor option.
+  if (argc > 1 && argv[0] == StringRef("-flavor")) {
+    if (argc <= 2)
+      WithColor::error() << "missing arg value for '-flavor'\n";
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
+
+  if (printTarget)
+    WithColor::note() << "Target: " << targetTriple.str() << "\n";
+
+  return Result;
+}
