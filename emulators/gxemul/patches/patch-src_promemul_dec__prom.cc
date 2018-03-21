$NetBSD: patch-src_promemul_dec__prom.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/promemul/dec_prom.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/promemul/dec_prom.cc
@@ -645,7 +645,7 @@ int decstation_prom_emul(struct cpu *cpu
 			cpu->running = 0;
 			break;
 		default:
-			fatal("DEC prom emulation: unknown rex() a0=0x%"PRIx64
+			fatal("DEC prom emulation: unknown rex() a0=0x%" PRIx64
 			    " ('%c')\n",
 			    (int64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
 			    (char) cpu->cd.mips.gpr[MIPS_GPR_A0]);
@@ -673,4 +673,3 @@ int decstation_prom_emul(struct cpu *cpu
 
 	return 1;
 }
-
