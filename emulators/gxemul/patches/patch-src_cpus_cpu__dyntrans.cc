$NetBSD: patch-src_cpus_cpu__dyntrans.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/cpu_dyntrans.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_dyntrans.cc
@@ -79,10 +79,10 @@ static void gather_statistics(struct cpu
 			a += low_pc << DYNTRANS_INSTR_ALIGNMENT_SHIFT;
 			if (cpu->is_32bit)
 				snprintf(buf + strlen(buf), sizeof(buf),
-				    "0x%08"PRIx32, (uint32_t)a);
+				    "0x%08" PRIx32, (uint32_t)a);
 			else
 				snprintf(buf + strlen(buf), sizeof(buf),
-				    "0x%016"PRIx64, (uint64_t)a);
+				    "0x%016" PRIx64, (uint64_t)a);
 			break;
 		case 'v':
 			/*  Virtual program counter address:  */
@@ -92,10 +92,10 @@ static void gather_statistics(struct cpu
 			a += low_pc << DYNTRANS_INSTR_ALIGNMENT_SHIFT;
 			if (cpu->is_32bit)
 				snprintf(buf + strlen(buf), sizeof(buf),
-				    "0x%08"PRIx32, (uint32_t)a);
+				    "0x%08" PRIx32, (uint32_t)a);
 			else
 				snprintf(buf + strlen(buf), sizeof(buf),
-				    "0x%016"PRIx64, (uint64_t)a);
+				    "0x%016" PRIx64, (uint64_t)a);
 			break;
 		}
 		i++;
@@ -141,7 +141,7 @@ static void gather_statistics(struct cpu
 			cpu->pc &= ~((DYNTRANS_IC_ENTRIES_PER_PAGE-1) << \
 			    DYNTRANS_INSTR_ALIGNMENT_SHIFT);		\
 			cpu->pc += (low_pc << DYNTRANS_INSTR_ALIGNMENT_SHIFT);\
-			printf("Crash at %016"PRIx64"\n", cpu->pc);	\
+			printf("Crash at %016" PRIx64 "\n", cpu->pc);	\
 			printf("nr of I calls: %lli\n", nr_of_I_calls);	\
 			printf("Next ic = %p\n", cpu->cd.		\
 				DYNTRANS_ARCH.next_ic);			\
@@ -533,9 +533,9 @@ void DYNTRANS_FUNCTION_TRACE_DEF(struct 
 			fatal("&%s", symbol);
 		else {
 			if (cpu->is_32bit)
-				fatal("0x%"PRIx32, (uint32_t)d);
+				fatal("0x%" PRIx32, (uint32_t)d);
 			else
-				fatal("0x%"PRIx64, (uint64_t)d);
+				fatal("0x%" PRIx64, (uint64_t)d);
 		}
 
 		if (x < n_args_to_print - 1)
@@ -612,7 +612,7 @@ void DYNTRANS_PC_TO_POINTERS_GENERIC(str
 	x1 = (cached_pc >> (64-DYNTRANS_L1N)) & mask1;
 	x2 = (cached_pc >> (64-DYNTRANS_L1N-DYNTRANS_L2N)) & mask2;
 	x3 = (cached_pc >> (64-DYNTRANS_L1N-DYNTRANS_L2N-DYNTRANS_L3N)) & mask3;
-	/*  fatal("X3: cached_pc=%016"PRIx64" x1=%x x2=%x x3=%x\n",
+	/*  fatal("X3: cached_pc=%016" PRIx64 " x1=%x x2=%x x3=%x\n",
 	    (uint64_t)cached_pc, (int)x1, (int)x2, (int)x3);  */
 	l2 = cpu->cd.DYNTRANS_ARCH.l1_64[x1];
 	/*  fatal("  l2 = %p\n", l2);  */
@@ -657,8 +657,8 @@ void DYNTRANS_PC_TO_POINTERS_GENERIC(str
 			 *  exception handler.
 			 */
 			/*  fatal("TODO: instruction vaddr=>paddr translation "
-			    "failed. vaddr=0x%"PRIx64"\n", (uint64_t)cached_pc);
-			fatal("!! cpu->pc=0x%"PRIx64"\n", (uint64_t)cpu->pc); */
+			    "failed. vaddr=0x%" PRIx64 "\n", (uint64_t)cached_pc);
+			fatal("!! cpu->pc=0x%" PRIx64 "\n", (uint64_t)cpu->pc); */
 
 			/*  If there was an exception, the PC has changed.
 			    Update cached_pc:  */
@@ -691,7 +691,7 @@ void DYNTRANS_PC_TO_POINTERS_GENERIC(str
 
 			/*  printf("EXCEPTION HANDLER: vaddr = 0x%x ==> "
 			    "paddr = 0x%x\n", (int)cpu->pc, (int)paddr);
-			fatal("!? cpu->pc=0x%"PRIx64"\n", (uint64_t)cpu->pc); */
+			fatal("!? cpu->pc=0x%" PRIx64 "\n", (uint64_t)cpu->pc); */
 
 			if (!ok) {
 				fatal("FATAL: could not find physical"
@@ -754,7 +754,7 @@ void DYNTRANS_PC_TO_POINTERS_GENERIC(str
 	if (physpage_ofs == 0) {
 		uint32_t previous_first_page_in_chain;
 
-		/*  fatal("CREATING page %lli (physaddr 0x%"PRIx64"), table "
+		/*  fatal("CREATING page %lli (physaddr 0x%" PRIx64 "), table "
 		    "index %i\n", (long long)pagenr, (uint64_t)physaddr,
 		    (int)table_index);  */
 
@@ -799,8 +799,8 @@ void DYNTRANS_PC_TO_POINTERS_GENERIC(str
 	cpu->cd.DYNTRANS_ARCH.next_ic = cpu->cd.DYNTRANS_ARCH.cur_ic_page +
 	    DYNTRANS_PC_TO_IC_ENTRY(cached_pc);
 
-	/*  printf("cached_pc=0x%016"PRIx64"  pagenr=%lli  table_index=%lli, "
-	    "physpage_ofs=0x%016"PRIx64"\n", (uint64_t)cached_pc, (long long)
+	/*  printf("cached_pc=0x%016" PRIx64 "  pagenr=%lli  table_index=%lli, "
+	    "physpage_ofs=0x%016" PRIx64 "\n", (uint64_t)cached_pc, (long long)
 	    pagenr, (long long)table_index, (uint64_t)physpage_ofs);  */
 }
 
@@ -861,8 +861,8 @@ have_it:
 	cpu->cd.DYNTRANS_ARCH.next_ic = cpu->cd.DYNTRANS_ARCH.cur_ic_page +
 	    DYNTRANS_PC_TO_IC_ENTRY(cached_pc);
 
-	/*  printf("cached_pc=0x%016"PRIx64"  pagenr=%lli  table_index=%lli, "
-	    "physpage_ofs=0x%016"PRIx64"\n", (uint64_t)cached_pc, (long long)
+	/*  printf("cached_pc=0x%016" PRIx64 "  pagenr=%lli  table_index=%lli, "
+	    "physpage_ofs=0x%016" PRIx64 "\n", (uint64_t)cached_pc, (long long)
 	    pagenr, (long long)table_index, (uint64_t)physpage_ofs);  */
 }
 #endif	/*  DYNTRANS_PC_TO_POINTERS_FUNC  */
@@ -1439,8 +1439,8 @@ void DYNTRANS_UPDATE_TRANSLATION_TABLE(s
 	vaddr_page &= 0xffffffffULL;
 
 	if (paddr_page > 0xffffffffULL) {
-		fatal("update_translation_table(): v=0x%016"PRIx64", h=%p w=%i"
-		    " p=0x%016"PRIx64"\n", vaddr_page, host_page, writeflag,
+		fatal("update_translation_table(): v=0x%016" PRIx64 ", h=%p w=%i"
+		    " p=0x%016" PRIx64 "\n", vaddr_page, host_page, writeflag,
 		    paddr_page);
 		exit(1);
 	}
@@ -1456,8 +1456,8 @@ void DYNTRANS_UPDATE_TRANSLATION_TABLE(s
 	struct DYNTRANS_L2_64_TABLE *l2;
 	struct DYNTRANS_L3_64_TABLE *l3;
 
-	/*  fatal("update_translation_table(): v=0x%016"PRIx64", h=%p w=%i"
-	    " p=0x%016"PRIx64"\n", (uint64_t)vaddr_page, host_page, writeflag,
+	/*  fatal("update_translation_table(): v=0x%016" PRIx64 ", h=%p w=%i"
+	    " p=0x%016" PRIx64 "\n", (uint64_t)vaddr_page, host_page, writeflag,
 	    (uint64_t)paddr_page);  */
 #endif
 
@@ -1730,11 +1730,11 @@ cpu->cd.DYNTRANS_ARCH.vph_tlb_entry[r].v
 					quiet_mode = tmp_old_quiet_mode;
 				}
 #ifdef MODE32
-				fatal("BREAKPOINT: pc = 0x%"PRIx32"\n(The "
+				fatal("BREAKPOINT: pc = 0x%" PRIx32 "\n(The "
 				    "instruction has not yet executed.)\n",
 				    (uint32_t)cpu->pc);
 #else
-				fatal("BREAKPOINT: pc = 0x%"PRIx64"\n(The "
+				fatal("BREAKPOINT: pc = 0x%" PRIx64 "\n(The "
 				    "instruction has not yet executed.)\n",
 				    (uint64_t)cpu->pc);
 #endif
@@ -1894,9 +1894,9 @@ bad:	/*
 
 	if (cpu->machine->instruction_trace) {
 		if (cpu->is_32bit)
-			fatal(" at 0x%"PRIx32"\n", (uint32_t)cpu->pc);
+			fatal(" at 0x%" PRIx32 "\n", (uint32_t)cpu->pc);
 		else
-			fatal(" at 0x%"PRIx64"\n", (uint64_t)cpu->pc);
+			fatal(" at 0x%" PRIx64 "\n", (uint64_t)cpu->pc);
 	} else {
 		fatal(":\n");
 		DISASSEMBLE(cpu, ib, 1, 0);
@@ -1923,4 +1923,3 @@ stop_running_translated:
 	ic->f(cpu, ic);
 
 #endif	/*  DYNTRANS_TO_BE_TRANSLATED_TAIL  */
-
