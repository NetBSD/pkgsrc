$NetBSD: patch-libsanitizer_sanitizer__common_sanitizer__common.h,v 1.1 2026/07/19 11:17:45 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libsanitizer/sanitizer_common/sanitizer_common.h.orig	2026-06-12 06:09:10.661588523 +0000
+++ libsanitizer/sanitizer_common/sanitizer_common.h
@@ -734,6 +734,7 @@ enum ModuleArch {
   kModuleArchARMV7S,
   kModuleArchARMV7K,
   kModuleArchARM64,
+  kModuleArchARM64E,
   kModuleArchLoongArch64,
   kModuleArchRISCV64,
   kModuleArchHexagon
@@ -807,6 +808,8 @@ inline const char *ModuleArchToString(Mo
       return "armv7k";
     case kModuleArchARM64:
       return "arm64";
+    case kModuleArchARM64E:
+      return "arm64e";
     case kModuleArchLoongArch64:
       return "loongarch64";
     case kModuleArchRISCV64:
