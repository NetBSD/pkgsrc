$NetBSD: patch-src_cpus_cpu__m88k__instr.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/cpu_m88k_instr.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_m88k_instr.cc
@@ -1515,14 +1515,14 @@ X(rte)
 		return;
 	}
 
-	/*  fatal("RTE: NIP=0x%08"PRIx32", FIP=0x%08"PRIx32"\n",
+	/*  fatal("RTE: NIP=0x%08" PRIx32 ", FIP=0x%08" PRIx32 "\n",
 	    cpu->cd.m88k.cr[M88K_CR_SNIP], cpu->cd.m88k.cr[M88K_CR_SFIP]);  */
 
 	quick_pc_to_pointers(cpu);
 	return;
 
 abort_dump:
-	fatal("RTE failed. NIP=0x%08"PRIx32", FIP=0x%08"PRIx32"\n",
+	fatal("RTE failed. NIP=0x%08" PRIx32 ", FIP=0x%08" PRIx32 "\n",
 	    cpu->cd.m88k.cr[M88K_CR_SNIP], cpu->cd.m88k.cr[M88K_CR_SFIP]);
 
 	ABORT_EXECUTION;
@@ -1833,7 +1833,7 @@ X(end_of_page2)
 	if (low_pc < 0 || low_pc > ((M88K_IC_ENTRIES_PER_PAGE+1)
 	    << M88K_INSTR_ALIGNMENT_SHIFT)) {
 		printf("[ end_of_page2: HUH? low_pc=%i, cpu->pc = %08"
-		    PRIx32" ]\n", low_pc, (uint32_t) cpu->pc);
+		    PRIx32 " ]\n", low_pc, (uint32_t) cpu->pc);
 	}
 
 	/*  This doesn't count as an executed instruction.  */
@@ -2699,7 +2699,7 @@ X(to_be_translated)
 				if (iword == 0xf400fc00)
 					ic->f = instr(rte);
 				else {
-					fatal("unimplemented rte variant: 0x%08"PRIx32"\n", iword);
+					fatal("unimplemented rte variant: 0x%08" PRIx32 "\n", iword);
 					goto bad;
 				}
 				break;
@@ -2722,4 +2722,3 @@ X(to_be_translated)
 #include "cpu_dyntrans.cc" 
 #undef	DYNTRANS_TO_BE_TRANSLATED_TAIL
 }
-
