$NetBSD: patch-src_cpus_cpu__sh.c,v 1.1 2026/04/19 22:48:15 mrg Exp $

Implement "synco" from SH4-A.  GCC 14 likes to emit it.


--- src/cpus/cpu_sh.c.orig	2021-04-22 11:04:18.000000000 -0700
+++ src/cpus/cpu_sh.c	2026-04-19 15:31:39.839125158 -0700
@@ -905,6 +905,8 @@ int sh_cpu_disassemble_instr(struct cpu *cpu, unsigned
 			debug("ocbi\t@r%i\n", r8);
 		else if (lo8 == 0xa3)
 			debug("ocbp\t@r%i\n", r8);
+		else if (iword == 0x00ab)
+			debug("synco\n");
 		else if (lo8 == 0xb3)
 			debug("ocbwb\t@r%i\n", r8);
 		else if (lo8 == 0xc3)
