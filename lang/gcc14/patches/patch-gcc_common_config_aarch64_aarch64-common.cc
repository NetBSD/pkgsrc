$NetBSD: patch-gcc_common_config_aarch64_aarch64-common.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/common/config/aarch64/aarch64-common.cc
+++ gcc/common/config/aarch64/aarch64-common.cc
@@ -298,8 +298,12 @@ aarch64_get_extension_string_for_isa_flags

      However, assemblers with Armv8-R AArch64 support should not have this
      issue, so we don't need this fix when targeting Armv8-R.  */
-  auto explicit_flags = (!(current_flags & AARCH64_FL_V8R)
-			 ? AARCH64_FL_CRC : 0);
+  aarch64_feature_flags explicit_flags =
+#ifndef DISABLE_AARCH64_AS_CRC_BUGFIX
+     (!(current_flags & AARCH64_ISA_V8R) ? AARCH64_FL_CRC : 0);
+#else
+     0;
+#endif

   /* Add the features in isa_flags & ~current_flags using the smallest
      possible number of extensions.  We can do this by iterating over the
@@ -329,7 +333,10 @@ aarch64_get_extension_string_for_isa_flags
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
@@ -358,7 +365,10 @@ aarch64_get_extension_string_for_isa_flags
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
