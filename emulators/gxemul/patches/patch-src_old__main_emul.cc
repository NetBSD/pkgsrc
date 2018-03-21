$NetBSD: patch-src_old__main_emul.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/old_main/emul.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/old_main/emul.cc
@@ -118,7 +118,7 @@ static void add_breakpoints(struct machi
 
 		m->breakpoints.addr[i] = dp;
 
-		debug("breakpoint %i: 0x%"PRIx64, i, dp);
+		debug("breakpoint %i: 0x%" PRIx64, i, dp);
 		if (string_flag)
 			debug(" (%s)", m->breakpoints.string[i]);
 		debug("\n");
@@ -658,26 +658,26 @@ void emul_machine_setup(struct machine *
 
 	case ARCH_MIPS:
 		if (cpu->is_32bit) {
-			debug("0x%08"PRIx32, (uint32_t)
+			debug("0x%08" PRIx32, (uint32_t)
 			    m->cpus[m->bootstrap_cpu]->pc);
 			if (cpu->cd.mips.gpr[MIPS_GPR_GP] != 0)
-				debug(" (gp=0x%08"PRIx32")", (uint32_t)
+				debug(" (gp=0x%08" PRIx32 ")", (uint32_t)
 				    m->cpus[m->bootstrap_cpu]->cd.mips.gpr[
 				    MIPS_GPR_GP]);
 		} else {
-			debug("0x%016"PRIx64, (uint64_t)
+			debug("0x%016" PRIx64, (uint64_t)
 			    m->cpus[m->bootstrap_cpu]->pc);
 			if (cpu->cd.mips.gpr[MIPS_GPR_GP] != 0)
-				debug(" (gp=0x%016"PRIx64")", (uint64_t)
+				debug(" (gp=0x%016" PRIx64 ")", (uint64_t)
 				    cpu->cd.mips.gpr[MIPS_GPR_GP]);
 		}
 		break;
 
 	default:
 		if (cpu->is_32bit)
-			debug("0x%08"PRIx32, (uint32_t) cpu->pc);
+			debug("0x%08" PRIx32, (uint32_t) cpu->pc);
 		else
-			debug("0x%016"PRIx64, (uint64_t) cpu->pc);
+			debug("0x%016" PRIx64, (uint64_t) cpu->pc);
 	}
 	debug("\n");
 
@@ -926,4 +926,3 @@ void emul_run(struct emul *emul)
 
 	console_deinit_main();
 }
-
