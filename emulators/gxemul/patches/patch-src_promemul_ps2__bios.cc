$NetBSD: patch-src_promemul_ps2__bios.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/promemul/ps2_bios.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/promemul/ps2_bios.cc
@@ -59,12 +59,12 @@ int playstation2_sifbios_emul(struct cpu
 		cpu->cd.mips.gpr[MIPS_GPR_V0] = 0x200;		/*  TODO  */
 		break;
 	case 1:			/*  halt(int mode)  */
-		debug("[ SIFBIOS halt(0x%"PRIx64") ]\n",
+		debug("[ SIFBIOS halt(0x%" PRIx64 ") ]\n",
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A1]);
 		cpu->running = 0;
 		break;
 	case 2:			/*  setdve(int mode)  */
-		debug("[ SIFBIOS setdve(0x%"PRIx64") ]\n",
+		debug("[ SIFBIOS setdve(0x%" PRIx64 ") ]\n",
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A1]);
 		break;
 	case 3:			/*  putchar(int ch)  */
@@ -108,8 +108,8 @@ int playstation2_sifbios_emul(struct cpu
 		cpu->cd.mips.gpr[MIPS_GPR_V0] = 1;		/*  TODO  */
 		break;
 	case 64:
-		fatal("[ SIFBIOS SBR_IOPH_INIT(0x%"PRIx32",0x%"PRIx32",0x%"
-		    PRIx32"): TODO ]\n",
+		fatal("[ SIFBIOS SBR_IOPH_INIT(0x%" PRIx32 ",0x%" PRIx32 ",0x%"
+		    PRIx32 "): TODO ]\n",
 		    (uint32_t) cpu->cd.mips.gpr[MIPS_GPR_A1],
 		    (uint32_t) cpu->cd.mips.gpr[MIPS_GPR_A2],
 		    (uint32_t) cpu->cd.mips.gpr[MIPS_GPR_A3]);
@@ -163,7 +163,7 @@ int playstation2_sifbios_emul(struct cpu
 		cpu->cd.mips.gpr[MIPS_GPR_V0] = 0;
 		break;
 	case 65:
-		fatal("[ SIFBIOS alloc iop heap(0x"PRIx32") ]\n",
+		fatal("[ SIFBIOS alloc iop heap(0x" PRIx32 ") ]\n",
 		    (uint32_t)cpu->cd.mips.gpr[MIPS_GPR_A1]);
 
 		/*
@@ -232,4 +232,3 @@ int playstation2_sifbios_emul(struct cpu
 
 	return 1;
 }
-
