$NetBSD: patch-target-i386_helper.h,v 1.1 2017/03/04 15:11:11 spz Exp $

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

--- target-i386/helper.h.orig	2016-12-20 20:16:50.000000000 +0000
+++ target-i386/helper.h	2017-03-03 04:41:00.000000000 +0000
@@ -79,6 +79,7 @@ DEF_HELPER_2(cmpxchg16b_unlocked, void, 
 DEF_HELPER_2(cmpxchg16b, void, env, tl)
 #endif
 DEF_HELPER_1(single_step, void, env)
+DEF_HELPER_1(rechecking_single_step, void, env)
 DEF_HELPER_1(cpuid, void, env)
 DEF_HELPER_1(rdtsc, void, env)
 DEF_HELPER_1(rdtscp, void, env)
