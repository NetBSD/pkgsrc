$NetBSD: patch-target-i386_translate.c,v 1.1 2017/03/04 15:11:11 spz Exp $

from upstream:
 commit c52ab08aee6f7d4717fc6b517174043126bd302f
 Author: Doug Evans <dje@google.com>
 Date:   Tue Dec 6 23:06:30 2016 +0000

     target-i386: Fix eflags.TF/#DB handling of syscall/sysret insns

     The syscall and sysret instructions behave a bit differently:
     TF is checked after the instruction completes.
     This allows the o/s to disable #DB at a syscall by adding TF to FMASK.
     And then when the sysret is executed the #DB is taken "as if" the
     syscall insn just completed.

 commit 410e98146ffde201ab4c778823ac8beaa74c4c3f
 Author: Doug Evans <dje@google.com>
 Date:   Sat Dec 24 20:29:33 2016 +0000

     target/i386: Fix bad patch application to translate.c

     In commit c52ab08aee6f7d4717fc6b517174043126bd302f,
     the patch snippet for the "syscall" insn got applied to "iret".

--- target-i386/translate.c.orig	2016-12-20 20:16:50.000000000 +0000
+++ target-i386/translate.c	2017-03-03 04:39:24.000000000 +0000
@@ -2500,8 +2500,10 @@ static void gen_bnd_jmp(DisasContext *s)
 }
 
 /* Generate an end of block. Trace exception is also generated if needed.
-   If IIM, set HF_INHIBIT_IRQ_MASK if it isn't already set.  */
-static void gen_eob_inhibit_irq(DisasContext *s, bool inhibit)
+   If INHIBIT, set HF_INHIBIT_IRQ_MASK if it isn't already set.
+   If RECHECK_TF, emit a rechecking helper for #DB, ignoring the state of
+   S->TF.  This is used by the syscall/sysret insns.  */
+static void gen_eob_worker(DisasContext *s, bool inhibit, bool recheck_tf)
 {
     gen_update_cc_op(s);
 
@@ -2517,6 +2519,9 @@ static void gen_eob_inhibit_irq(DisasCon
     }
     if (s->singlestep_enabled) {
         gen_helper_debug(cpu_env);
+   } else if (recheck_tf) {
+        gen_helper_rechecking_single_step(cpu_env);
+        tcg_gen_exit_tb(0);
     } else if (s->tf) {
         gen_helper_single_step(cpu_env);
     } else {
@@ -2525,10 +2530,17 @@ static void gen_eob_inhibit_irq(DisasCon
     s->is_jmp = DISAS_TB_JUMP;
 }
 
+/* End of block.
+   If INHIBIT, set HF_INHIBIT_IRQ_MASK if it isn't already set.  */
+static void gen_eob_inhibit_irq(DisasContext *s, bool inhibit)
+{
+    gen_eob_worker(s, inhibit, false);
+}
+
 /* End of block, resetting the inhibit irq flag.  */
 static void gen_eob(DisasContext *s)
 {
-    gen_eob_inhibit_irq(s, false);
+    gen_eob_worker(s, false, false);
 }
 
 /* generate a jump to eip. No segment change must happen before as a
@@ -7104,7 +7116,10 @@ static target_ulong disas_insn(CPUX86Sta
         gen_update_cc_op(s);
         gen_jmp_im(pc_start - s->cs_base);
         gen_helper_syscall(cpu_env, tcg_const_i32(s->pc - pc_start));
-        gen_eob(s);
+        /* TF handling for the syscall insn is different. The TF bit is  checked
+           after the syscall insn completes. This allows #DB to not be
+           generated after one has entered CPL0 if TF is set in FMASK.  */
+        gen_eob_worker(s, false, true);
         break;
     case 0x107: /* sysret */
         if (!s->pe) {
@@ -7115,7 +7130,11 @@ static target_ulong disas_insn(CPUX86Sta
             if (s->lma) {
                 set_cc_op(s, CC_OP_EFLAGS);
             }
-            gen_eob(s);
+            /* TF handling for the sysret insn is different. The TF bit is
+               checked after the sysret insn completes. This allows #DB to be
+               generated "as if" the syscall insn in userspace has just
+               completed.  */
+            gen_eob_worker(s, false, true);
         }
         break;
 #endif
