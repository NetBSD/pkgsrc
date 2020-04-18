$NetBSD: patch-ELF_Driver.cpp,v 1.8 2020/04/18 08:00:50 adam Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Driver.cpp.orig	2020-03-23 15:01:02.000000000 +0000
+++ ELF/Driver.cpp
@@ -132,7 +132,7 @@ static std::tuple<ELFKind, uint16_t, uin
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
 
@@ -879,6 +882,7 @@ static void readConfigs(opt::InputArgLis
       args.hasFlag(OPT_export_dynamic, OPT_no_export_dynamic, false);
   config->filterList = args::getStrings(args, OPT_filter);
   config->fini = args.getLastArgValue(OPT_fini, "_fini");
+  config->fixCortexA53Errata835769 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->fixCortexA53Errata843419 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->fixCortexA8 = args.hasArg(OPT_fix_cortex_a8);
   config->forceBTI = hasZOption(args, "force-bti");
