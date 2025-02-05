$NetBSD: patch-gcc_c-family_c-common.cc,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-common.cc
+++ gcc/c-family/c-common.cc
@@ -346,7 +346,11 @@ static constexpr hf_feature_info has_feature_table[] =
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
