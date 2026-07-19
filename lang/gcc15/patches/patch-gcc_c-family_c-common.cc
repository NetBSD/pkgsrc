$NetBSD: patch-gcc_c-family_c-common.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c-family/c-common.cc.orig	2026-06-12 06:09:06.071517475 +0000
+++ gcc/c-family/c-common.cc
@@ -354,7 +354,11 @@ static constexpr hf_feature_info has_fea
   { "enumerator_attributes",		  HF_FLAG_NONE, 0 },
   { "tls",				  HF_FLAG_NONE, 0 },
   { "gnu_asm_goto_with_outputs",	  HF_FLAG_EXT, 0 },
-  { "gnu_asm_goto_with_outputs_full",	  HF_FLAG_EXT, 0 }
+  { "gnu_asm_goto_with_outputs_full",	  HF_FLAG_EXT, 0 },
+  { "attribute_availability",		  HF_FLAG_NONE, 0 },
+  { "attribute_availability_with_message",  HF_FLAG_NONE, 0 },
+  { "attribute_availability_with_replacement",  HF_FLAG_NONE, 0 },
+  { "attribute_availability_with_version_underscores",  HF_FLAG_NONE, 0 }
 };

 /* Global visibility options.  */
@@ -392,8 +396,8 @@ static bool nonnull_check_p (tree, unsig
 */
 const struct c_common_resword c_common_reswords[] =
 {
-  { "_Alignas",		RID_ALIGNAS,   D_CONLY },
-  { "_Alignof",		RID_ALIGNOF,   D_CONLY },
+  { "_Alignas",		RID_ALIGNAS,   D_EXT_C_IN_CXX },
+  { "_Alignof",		RID_ALIGNOF,   D_EXT_C_IN_CXX },
   { "_Atomic",		RID_ATOMIC,    D_CONLY },
   { "_BitInt",		RID_BITINT,    D_CONLY },
   { "_Bool",		RID_BOOL,      D_CONLY },
@@ -413,7 +417,7 @@ const struct c_common_resword c_common_r
   { "_Fract",           RID_FRACT,     D_CONLY | D_EXT },
   { "_Accum",           RID_ACCUM,     D_CONLY | D_EXT },
   { "_Sat",             RID_SAT,       D_CONLY | D_EXT },
-  { "_Static_assert",   RID_STATIC_ASSERT, D_CONLY },
+  { "_Static_assert",   RID_STATIC_ASSERT, D_EXT_C_IN_CXX },
   { "_Noreturn",        RID_NORETURN,  D_CONLY },
   { "_Generic",         RID_GENERIC,   D_CONLY },
   { "_Thread_local",    RID_THREAD,    D_CONLY },
