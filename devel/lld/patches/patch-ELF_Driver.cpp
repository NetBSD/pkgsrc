$NetBSD: patch-ELF_Driver.cpp,v 1.6 2019/11/03 12:10:29 kamil Exp $

Cherry-pick upstream patch commit 2a0fcae3d4d1fd85d6ae8378d7c6f12430c0087d
[lld] [ELF] Add '-z nognustack' opt to suppress emitting PT_GNU_STAC dummy option for an AArch64 erratum.    

Add dummy option for an AArch64 erratum.

--- ELF/Driver.cpp.orig	2019-07-17 14:54:02.000000000 +0000
+++ ELF/Driver.cpp
@@ -129,7 +129,7 @@ static std::tuple<ELFKind, uint16_t, uin
   std::pair<ELFKind, uint16_t> ret =
       StringSwitch<std::pair<ELFKind, uint16_t>>(s)
           .Cases("aarch64elf", "aarch64linux", "aarch64_elf64_le_vec",
-                 {ELF64LEKind, EM_AARCH64})
+                 "aarch64nbsd", {ELF64LEKind, EM_AARCH64})
           .Cases("armelf", "armelf_linux_eabi", {ELF32LEKind, EM_ARM})
           .Case("elf32_x86_64", {ELF32LEKind, EM_X86_64})
           .Cases("elf32btsmip", "elf32btsmipn32", {ELF32BEKind, EM_MIPS})
@@ -296,6 +296,9 @@ static void checkOptions() {
   if (config->emachine == EM_MIPS && config->gnuHash)
     error("the .gnu.hash section is not compatible with the MIPS target");
 
+  if (config->fixCortexA53Errata835769 && config->emachine != EM_AARCH64)
+    error("--fix-cortex-a53-835769 is only supported on AArch64 targets");
+
   if (config->fixCortexA53Errata843419 && config->emachine != EM_AARCH64)
     error("--fix-cortex-a53-843419 is only supported on AArch64 targets");
 
@@ -373,6 +376,20 @@ static bool getZFlag(opt::InputArgList &
   return Default;
 }
 
+static GnuStackKind getZGnuStack(opt::InputArgList &args) {
+  for (auto *arg : args.filtered_reverse(OPT_z)) {
+    if (StringRef("execstack") == arg->getValue())
+      return GnuStackKind::Exec;
+    if (StringRef("noexecstack") == arg->getValue())
+      return GnuStackKind::NoExec;
+    if (StringRef("nognustack") == arg->getValue())
+      return GnuStackKind::None;
+  }
+
+  // default
+  return GnuStackKind::NoExec;
+}
+
 static bool isKnownZFlag(StringRef s) {
   return s == "combreloc" || s == "copyreloc" || s == "defs" ||
          s == "execstack" || s == "global" || s == "hazardplt" ||
@@ -380,6 +397,7 @@ static bool isKnownZFlag(StringRef s) {
          s == "keep-text-section-prefix" || s == "lazy" || s == "muldefs" ||
          s == "nocombreloc" || s == "nocopyreloc" || s == "nodefaultlib" ||
          s == "nodelete" || s == "nodlopen" || s == "noexecstack" ||
+         s == "nognustack" ||
          s == "nokeep-text-section-prefix" || s == "norelro" || s == "notext" ||
          s == "now" || s == "origin" || s == "relro" || s == "retpolineplt" ||
          s == "rodynamic" || s == "text" || s == "wxneeded" ||
@@ -828,6 +846,7 @@ static void readConfigs(opt::InputArgLis
       args.hasFlag(OPT_export_dynamic, OPT_no_export_dynamic, false);
   config->filterList = args::getStrings(args, OPT_filter);
   config->fini = args.getLastArgValue(OPT_fini, "_fini");
+  config->fixCortexA53Errata835769 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->fixCortexA53Errata843419 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->forceBTI = args.hasArg(OPT_force_bti);
   config->requireCET = args.hasArg(OPT_require_cet);
@@ -921,6 +940,7 @@ static void readConfigs(opt::InputArgLis
   config->zCopyreloc = getZFlag(args, "copyreloc", "nocopyreloc", true);
   config->zExecstack = getZFlag(args, "execstack", "noexecstack", false);
   config->zGlobal = hasZOption(args, "global");
+  config->zGnustack = getZGnuStack(args);
   config->zHazardplt = hasZOption(args, "hazardplt");
   config->zIfuncNoplt = hasZOption(args, "ifunc-noplt");
   config->zInitfirst = hasZOption(args, "initfirst");
