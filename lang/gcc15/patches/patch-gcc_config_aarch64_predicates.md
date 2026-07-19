$NetBSD: patch-gcc_config_aarch64_predicates.md,v 1.1 2026/07/19 11:17:43 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/config/aarch64/predicates.md.orig	2026-06-12 06:09:06.123518280 +0000
+++ gcc/config/aarch64/predicates.md
@@ -355,9 +355,24 @@
 (define_predicate "aarch64_prefetch_operand"
   (match_test "aarch64_address_valid_for_prefetch_p (op, false)"))
 
+(define_predicate "aarch64_unscaled_prefetch_operand"
+  (match_test "aarch64_address_valid_for_unscaled_prefetch_p (op, false)"))
+
 (define_predicate "aarch64_valid_symref"
   (match_code "const, symbol_ref, label_ref")
 {
+  if (TARGET_MACHO)
+    {
+      rtx x = op;
+      rtx offset;
+      split_const (x, &x, &offset);
+      if (GET_CODE (x) == CONST)
+	x = XEXP (x, 0);
+      if (GET_CODE (x) == UNSPEC && XINT (x, 1) == UNSPEC_SALT_ADDR)
+	x = XVECEXP (x, 0, 0);
+      if (SYMBOL_REF_P (x) && INTVAL (offset) < 0)
+        return false;
+    }
   return (aarch64_classify_symbolic_expression (op)
 	  != SYMBOL_FORCE_TO_MEM);
 })
