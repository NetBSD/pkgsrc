$NetBSD: patch-gcc_c-family_c-common.cc,v 1.2 2025/06/11 13:27:04 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-common.cc.orig	2025-05-23 11:02:04.244196764 +0000
+++ gcc/c-family/c-common.cc
@@ -346,7 +346,11 @@ static constexpr hf_feature_info has_fea
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
