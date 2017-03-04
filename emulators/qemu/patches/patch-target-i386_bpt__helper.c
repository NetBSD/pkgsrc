$NetBSD: patch-target-i386_bpt__helper.c,v 1.1 2017/03/04 15:11:11 spz Exp $

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

--- target-i386/bpt_helper.c.orig	2016-12-20 20:16:49.000000000 +0000
+++ target-i386/bpt_helper.c	2017-03-03 04:30:46.000000000 +0000
@@ -244,6 +244,13 @@ void helper_single_step(CPUX86State *env
     raise_exception(env, EXCP01_DB);
 }
 
+void helper_rechecking_single_step(CPUX86State *env)
+{
+    if ((env->eflags & TF_MASK) != 0) {
+        helper_single_step(env);
+    }
+}
+
 void helper_set_dr(CPUX86State *env, int reg, target_ulong t0)
 {
 #ifndef CONFIG_USER_ONLY
