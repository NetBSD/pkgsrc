$NetBSD: patch-gcc_config_aarch64_aarch64.md,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64.md
+++ gcc/config/aarch64/aarch64.md
@@ -363,6 +363,7 @@
     ;; Wraps a constant integer that should be multiplied by the number
     ;; of quadwords in an SME vector.
     UNSPEC_SME_VQ
+    UNSPEC_MACHOPIC_OFFSET	; Common to Mach-O ports.
 ])

 (define_c_enum "unspecv" [
@@ -995,6 +996,37 @@
   [(set_attr "type" "load_4")]
 )

+(define_insn "prefetch_unscaled"
+  [(prefetch (match_operand:DI 0 "aarch64_unscaled_prefetch_operand" "Du")
+            (match_operand:QI 1 "const_int_operand" "")
+            (match_operand:QI 2 "const_int_operand" ""))]
+  ""
+  {
+    const char * pftype[2][4] =
+    {
+      {"prfum\\tPLDL1STRM, %0",
+       "prfum\\tPLDL3KEEP, %0",
+       "prfum\\tPLDL2KEEP, %0",
+       "prfum\\tPLDL1KEEP, %0"},
+      {"prfum\\tPSTL1STRM, %0",
+       "prfum\\tPSTL3KEEP, %0",
+       "prfum\\tPSTL2KEEP, %0",
+       "prfum\\tPSTL1KEEP, %0"},
+    };
+
+    int locality = INTVAL (operands[2]);
+
+    gcc_assert (IN_RANGE (locality, 0, 3));
+
+    /* PRFUM accepts the same addresses as a 64-bit LDR so wrap
+       the address into a DImode MEM so that aarch64_print_operand knows
+       how to print it.  */
+    operands[0] = gen_rtx_MEM (DImode, operands[0]);
+    return pftype[INTVAL(operands[1])][locality];
+  }
+  [(set_attr "type" "load_4")]
+)
+
 (define_insn "trap"
   [(trap_if (const_int 1) (const_int 8))]
   ""
@@ -1447,7 +1479,7 @@
      [w  , m  ; load_4   , fp  , 4] ldr\t%s0, %1
      [m  , r Z; store_4  , *   , 4] str\t%w1, %0
      [m  , w  ; store_4  , fp  , 4] str\t%s1, %0
-     [r  , Usw; load_4   , *   , 8] adrp\t%x0, %A1;ldr\t%w0, [%x0, %L1]
+     [r  , Usw; load_4   , *   , 8] << TARGET_MACHO ? \"adrp\\t%x0, %A1\;ldr\\t%w0, [%x0, %O1]\" : \"adrp\\t%x0, %A1\;ldr\\t%w0, [%x0, %L1]\";
      [r  , Usa; adr      , *   , 4] adr\t%x0, %c1
      [r  , Ush; adr      , *   , 4] adrp\t%x0, %A1
      [w  , r Z; f_mcr    , fp  , 4] fmov\t%s0, %w1
@@ -1484,7 +1516,7 @@
      [w, m  ; load_8   , fp  , 4] ldr\t%d0, %1
      [m, r Z; store_8  , *   , 4] str\t%x1, %0
      [m, w  ; store_8  , fp  , 4] str\t%d1, %0
-     [r, Usw; load_8   , *   , 8] << TARGET_ILP32 ? "adrp\t%0, %A1;ldr\t%w0, [%0, %L1]" : "adrp\t%0, %A1;ldr\t%0, [%0, %L1]";
+     [r, Usw; load_8   , *   , 8] << TARGET_ILP32 ? (TARGET_MACHO ? \"adrp\\t%0, %A1\;ldr\\t%w0, [%0, %O1]\" : \"adrp\\t%0, %A1\;ldr\\t%w0, [%0, %L1]\") : (TARGET_MACHO ? \"adrp\\t%0, %A1\;ldr\\t%0, [%0, %O1]\" : \"adrp\\t%0, %A1\;ldr\\t%0, [%0, %L1]\");
      [r, Usa; adr      , *   , 4] adr\t%x0, %c1
      [r, Ush; adr      , *   , 4] adrp\t%x0, %A1
      [w, r Z; f_mcr    , fp  , 4] fmov\t%d0, %x1
@@ -7387,7 +7419,10 @@
 	(lo_sum:P (match_operand:P 1 "register_operand" "r")
 		  (match_operand 2 "aarch64_valid_symref" "S")))]
   ""
-  "add\\t%<w>0, %<w>1, :lo12:%c2"
+  { return TARGET_MACHO
+    ? "add\\t%<w>0, %<w>1, %J2;"
+    : "add\\t%<w>0, %<w>1, :lo12:%c2";
+  }
   [(set_attr "type" "alu_imm")]
 )
