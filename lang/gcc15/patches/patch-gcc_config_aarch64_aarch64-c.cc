$NetBSD: patch-gcc_config_aarch64_aarch64-c.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/config/aarch64/aarch64-c.cc.orig	2026-06-12 06:09:06.108518048 +0000
+++ gcc/config/aarch64/aarch64-c.cc
@@ -313,6 +313,16 @@ aarch64_cpu_cpp_builtins (cpp_reader *pf
 {
   aarch64_define_unconditional_macros (pfile);
   aarch64_update_cpp_builtins (pfile);
+
+  if (TARGET_MACHO)
+    {
+      builtin_define ("__builtin_copysignq=__builtin_copysignf128");
+      builtin_define ("__builtin_fabsq=__builtin_fabsf128");
+      builtin_define ("__builtin_huge_valq=__builtin_huge_valf128");
+      builtin_define ("__builtin_infq=__builtin_inff128");
+      builtin_define ("__builtin_nanq=__builtin_nanf128");
+      builtin_define ("__builtin_nansq=__builtin_nansf128");
+    }
 }

 /* Hook to validate the current #pragma GCC target and set the state, and
@@ -451,4 +461,8 @@ aarch64_register_pragmas (void)
   targetm.check_builtin_call = aarch64_check_builtin_call;

   c_register_pragma ("GCC", "aarch64", aarch64_pragma_aarch64);
+
+#ifdef REGISTER_SUBTARGET_PRAGMAS
+  REGISTER_SUBTARGET_PRAGMAS ();
+#endif
 }
