$NetBSD: patch-src_cpus_cpu__m88k__instr__loadstore.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/cpu_m88k_instr_loadstore.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_m88k_instr_loadstore.cc
@@ -161,7 +161,7 @@ void LS_GENERIC_N(struct cpu *cpu, struc
 		m88k_exception(cpu, M88K_EXCEPTION_MISALIGNED_ACCESS, 0);
 #else
 		fatal("{ m88k dyntrans alignment exception, size = %i,"
-		    " addr = %08"PRIx32", pc = %08"PRIx32" }\n", LS_SIZE,
+		    " addr = %08" PRIx32 ", pc = %08" PRIx32 " }\n", LS_SIZE,
 		    (uint32_t) addr, (uint32_t) cpu->pc);
 
 		/*  TODO: Generalize this into a abort_call, or similar:  */
@@ -450,4 +450,3 @@ void LS_N(struct cpu *cpu, struct m88k_i
 
 #endif	/*  store  */
 }
-
