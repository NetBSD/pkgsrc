$NetBSD: patch-target_sparc_translate.c,v 1.1 2020/11/02 17:17:15 martin Exp $

Patch from upstream (not integrated there yet) to work around %pc/%npc
being set to invalid values via ptrace, triggered by the NetBSD ptrace
ATF tests. Real hardware seems to hardcode the lower bits to zero too.

--- target/sparc/translate.c.orig	2020-08-11 21:17:15.000000000 +0200
+++ target/sparc/translate.c	2020-11-02 18:04:50.507211101 +0100
@@ -4525,6 +4525,7 @@
 
                                     r_tsptr = tcg_temp_new_ptr();
                                     gen_load_trap_state_at_tl(r_tsptr, cpu_env);
+                                    tcg_gen_andi_tl(cpu_tmp0, cpu_tmp0, ~3);
                                     tcg_gen_st_tl(cpu_tmp0, r_tsptr,
                                                   offsetof(trap_state, tpc));
                                     tcg_temp_free_ptr(r_tsptr);
@@ -4536,6 +4537,7 @@
 
                                     r_tsptr = tcg_temp_new_ptr();
                                     gen_load_trap_state_at_tl(r_tsptr, cpu_env);
+                                    tcg_gen_andi_tl(cpu_tmp0, cpu_tmp0, ~3);
                                     tcg_gen_st_tl(cpu_tmp0, r_tsptr,
                                                   offsetof(trap_state, tnpc));
                                     tcg_temp_free_ptr(r_tsptr);
