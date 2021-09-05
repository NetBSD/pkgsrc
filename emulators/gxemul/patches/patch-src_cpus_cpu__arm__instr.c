$NetBSD: patch-src_cpus_cpu__arm__instr.c,v 1.1 2021/09/05 07:27:13 skrll Exp $

--- src/cpus/cpu_arm_instr.c.orig	2021-04-22 18:04:18.000000000 +0000
+++ src/cpus/cpu_arm_instr.c
@@ -3534,6 +3534,9 @@ X(to_be_translated)
 				int lsb = (iword >> 7) & 31;
 				int width = 1 + ((iword >> 16) & 31);
 				ic->arg[2] = (width << 16) + lsb;
+			} else if ((iword & 0x07f000f0) == 0x07f000f0) {
+				ic->f = cond_instr(und);
+				ic->arg[0] = addr & 0xfff;
 			} else {
 				if (!cpu->translation_readahead)
 					fatal("unimplemented special non-loadstore encoding!\n");
