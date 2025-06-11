$NetBSD: patch-gcc_config_aarch64_predicates.md,v 1.2 2025/06/11 13:27:05 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/predicates.md.orig	2025-05-23 11:02:04.288197457 +0000
+++ gcc/config/aarch64/predicates.md
@@ -352,9 +352,24 @@
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
