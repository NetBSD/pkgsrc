$NetBSD: patch-src_cpus_cpu_mips.cc,v 1.3 2019/01/04 13:35:16 ryoon Exp $

implement trap with immediate instructions present in MIPS32.

--- src/cpus/cpu_mips.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/cpus/cpu_mips.cc
@@ -1462,6 +1462,12 @@ int mips_cpu_disassemble_instr(struct cp
 		case REGIMM_BLTZALL:
 		case REGIMM_BGEZAL:
 		case REGIMM_BGEZALL:
+		case REGIMM_TGEI:
+		case REGIMM_TGEIU:
+		case REGIMM_TLTI:
+		case REGIMM_TLTIU:
+		case REGIMM_TEQI:
+		case REGIMM_TNEI:
 			debug("%s\t%s,", regimm_names[regimm5], regnames[rs]);
 
 			addr = (dumpaddr + 4) + (imm << 2);
