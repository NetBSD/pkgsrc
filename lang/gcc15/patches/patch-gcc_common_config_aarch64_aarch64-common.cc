$NetBSD: patch-gcc_common_config_aarch64_aarch64-common.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/common/config/aarch64/aarch64-common.cc.orig	2026-06-12 06:09:06.103685764 +0000
+++ gcc/common/config/aarch64/aarch64-common.cc
@@ -644,8 +644,12 @@ aarch64_get_extension_string_for_isa_fla

      However, assemblers with Armv8-R AArch64 support should not have this
      issue, so we don't need this fix when targeting Armv8-R.  */
-  auto explicit_flags = (!(current_flags & AARCH64_FL_V8R)
-			 ? AARCH64_FL_CRC : 0);
+  aarch64_feature_flags explicit_flags =
+#ifndef DISABLE_AARCH64_AS_CRC_BUGFIX
+     (!(current_flags & AARCH64_FL_V8R) ? AARCH64_FL_CRC : 0);
+#else
+     0;
+#endif

   /* Add the features in isa_flags & ~current_flags using the smallest
      possible number of extensions.  We can do this by iterating over the
@@ -675,7 +679,10 @@ aarch64_get_extension_string_for_isa_fla
     if (added & opt.flag_canonical)
       {
 	outstr += "+";
-	outstr += opt.name;
+	if (startswith (opt.name, "rdm"))
+	  outstr += "rdm";
+	else
+	  outstr += opt.name;
       }

   /* Remove the features in current_flags & ~isa_flags.  If the feature does
@@ -704,7 +711,10 @@ aarch64_get_extension_string_for_isa_fla
 	{
 	  current_flags &= ~opt.flags_off;
 	  outstr += "+no";
-	  outstr += opt.name;
+	  if (startswith (opt.name, "rdm"))
+	    outstr += "rdm";
+	  else
+	    outstr += opt.name;
 	}
     }
