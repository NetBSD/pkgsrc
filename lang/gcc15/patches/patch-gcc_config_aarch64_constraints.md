$NetBSD: patch-gcc_config_aarch64_constraints.md,v 1.1 2026/07/19 11:17:43 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/config/aarch64/constraints.md.orig	2026-06-12 06:09:06.122518264 +0000
+++ gcc/config/aarch64/constraints.md
@@ -206,7 +206,9 @@
    A constraint that matches a small GOT access."
   (and (match_code "const,symbol_ref")
        (match_test "aarch64_classify_symbolic_expression (op)
-		     == SYMBOL_SMALL_GOT_4G")))
+		     == SYMBOL_SMALL_GOT_4G
+		    || aarch64_classify_symbolic_expression (op)
+		     == SYMBOL_MO_SMALL_GOT")))
 
 (define_constraint "Uss"
   "@internal
@@ -581,6 +583,11 @@
  An address valid for a prefetch instruction."
  (match_test "aarch64_address_valid_for_prefetch_p (op, true)"))
 
+(define_address_constraint "Du"
+  "@internal
+ An address valid for a prefetch instruction with an unscaled offset."
+ (match_test "aarch64_address_valid_for_unscaled_prefetch_p (op, true)"))
+
 (define_constraint "vgb"
   "@internal
    A constraint that matches an immediate offset valid for SVE LD1B
