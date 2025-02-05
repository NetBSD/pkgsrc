$NetBSD: patch-gcc_config_aarch64_constraints.md,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/constraints.md
+++ gcc/config/aarch64/constraints.md
@@ -203,7 +203,9 @@
    A constraint that matches a small GOT access."
   (and (match_code "const,symbol_ref")
        (match_test "aarch64_classify_symbolic_expression (op)
-		     == SYMBOL_SMALL_GOT_4G")))
+		     == SYMBOL_SMALL_GOT_4G
+		    || aarch64_classify_symbolic_expression (op)
+		     == SYMBOL_MO_SMALL_GOT")))

 (define_constraint "Uss"
   "@internal
@@ -574,6 +576,11 @@
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
