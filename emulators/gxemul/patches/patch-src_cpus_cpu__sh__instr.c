$NetBSD: patch-src_cpus_cpu__sh__instr.c,v 1.1 2026/04/19 22:48:15 mrg Exp $

Implement SH4-A "synco" as a nop for now.


--- src/cpus/cpu_sh_instr.c.orig	2021-04-22 11:04:18.000000000 -0700
+++ src/cpus/cpu_sh_instr.c	2026-04-19 15:41:22.590946901 -0700
@@ -3387,6 +3387,12 @@ X(to_be_translated)
 			/*  STC Rm_BANK, Rn  */
 			ic->f = instr(copy_privileged_register);
 			ic->arg[0] = (size_t)&cpu->cd.sh.r_bank[(lo8 >> 4) & 7];
+		} else if (iword == 0x00ab) {
+			/*  SYNCO  */
+			/*  Treat as nop for now:  */
+			/*  TODO: Implement this.  */
+			ic->f = instr(nop);
+			break;
 		} else if (iword == SH_INVALID_INSTR) {
 			/*  PROM emulation (GXemul specific)  */
 			ic->f = instr(prom_emul);
