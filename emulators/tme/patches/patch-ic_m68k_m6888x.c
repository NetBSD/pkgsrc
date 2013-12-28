$NetBSD: patch-ic_m68k_m6888x.c,v 1.1 2013/12/28 19:16:48 martin Exp $

Patch from upstream CVS: fix emulation of fmovel #IMM, %fpcr

--- ic/m68k/m6888x.c.orig	2007-08-25 22:37:30.000000000 +0200
+++ ic/m68k/m6888x.c	2013-12-23 13:12:54.000000000 +0100
@@ -1765,9 +1765,10 @@ TME_M68K_INSN(tme_m68k_fmovemctl)
   }
 
   /* if this isn't a data register direct EA or an address register
-     direct EA, this instruction can fault: */
+     direct EA or an immediate EA, this instruction can fault: */
   if (ea_mode != 0
-      && ea_mode != 1) {
+      && ea_mode != 1
+      && (ea_mode != 7 || ea_reg != 4)) {
     TME_M68K_INSN_CANFAULT;
   }
 
@@ -1822,6 +1823,14 @@ TME_M68K_INSN(tme_m68k_fmovemctl)
       }
     }
 
+    /* if this is an immediate EA: */
+    else if (ea_mode == 7 && ea_reg == 4) {
+      if (__tme_predict_false(register_to_memory)) {
+	TME_M68K_INSN_EXCEPTION(TME_M68K_EXCEPTION_ILL);
+      }
+      *value = ic->tme_m68k_ireg_imm32;
+    }
+
     /* otherwise, this is a memory EA: */
     else {
       if (register_to_memory) {
