$NetBSD: patch-src_cpus_cpu_mips.cc,v 1.1 2016/03/29 19:03:07 mrg Exp $

implement trap with immediate instructions present in MIPS32.

--- src/cpus/cpu_mips.cc.orig	2014-08-17 01:45:15.000000000 -0700
+++ src/cpus/cpu_mips.cc	2016-03-28 11:51:05.000000000 -0700
@@ -1457,6 +1457,12 @@
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
