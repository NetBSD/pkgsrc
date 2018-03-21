$NetBSD: patch-src_cpus_cpu_mips_instr.cc,v 1.2 2018/03/21 17:39:42 kamil Exp $

implement trap with immediate instructions present in MIPS32.

Fix C++11 literals.

--- src/cpus/cpu_mips_instr.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_mips_instr.cc
@@ -1461,6 +1461,92 @@ X(tne)
 	}
 }
 
+/*
+ *  1-register + 1-immediate:
+ *
+ *  arg[0] = ptr to rs
+ *  arg[1] = ([u]int16_t) immediate value
+ */
+
+X(tgei)
+{
+	MODE_int_t a = reg(ic->arg[0]), b = (int16_t)ic->arg[1];
+	if (a >= b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+X(tgeiu)
+{
+	MODE_uint_t a = reg(ic->arg[0]), b = ic->arg[1];
+	if (a >= b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+X(tlti)
+{
+	MODE_int_t a = reg(ic->arg[0]), b = (int16_t)ic->arg[1];
+	if (a < b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+X(tltiu)
+{
+	MODE_uint_t a = reg(ic->arg[0]), b = ic->arg[1];
+	if (a < b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+X(teqi)
+{
+	MODE_uint_t a = reg(ic->arg[0]), b = (int16_t)ic->arg[1];
+	if (a == b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+X(tnei)
+{
+	MODE_uint_t a = reg(ic->arg[0]), b = ic->arg[1];
+	if (a != b) {
+		/*  Synch. PC and cause an exception:  */
+		int low_pc = ((size_t)ic - (size_t)cpu->cd.mips.cur_ic_page)
+		    / sizeof(struct mips_instr_call);
+		cpu->pc &= ~((MIPS_IC_ENTRIES_PER_PAGE-1)
+		    << MIPS_INSTR_ALIGNMENT_SHIFT);
+		cpu->pc += (low_pc << MIPS_INSTR_ALIGNMENT_SHIFT);
+		mips_cpu_exception(cpu, EXCEPTION_TR, 0, 0, 0, 0, 0, 0);
+	}
+}
+
 
 /*
  *  3-register arithmetic instructions:
@@ -3983,7 +4069,7 @@ X(to_be_translated)
 		if (cpu->delay_slot) {
 			if (!cpu->translation_readahead)
 				fatal("TODO: branch in delay slot (=%i)? (3);"
-				    " addr=%016"PRIx64" iword=%08"PRIx32"\n",
+				    " addr=%016" PRIx64 " iword=%08" PRIx32 "\n",
 				    cpu->delay_slot, (uint64_t)addr, iword);
 			goto bad;
 		}
@@ -4446,6 +4532,37 @@ X(to_be_translated)
 			}
 			break;
 
+		case REGIMM_TGEI:
+		case REGIMM_TGEIU:
+		case REGIMM_TLTI:
+		case REGIMM_TLTIU:
+		case REGIMM_TEQI:
+		case REGIMM_TNEI:
+			switch (rt) {
+			case REGIMM_TGEI:
+				ic->f = instr(tgei);
+				break;
+			case REGIMM_TGEIU:
+				ic->f = instr(tgeiu);
+				break;
+			case REGIMM_TLTI:
+				ic->f = instr(tlti);
+				break;
+			case REGIMM_TLTIU:
+				ic->f = instr(tltiu);
+				break;
+			case REGIMM_TEQI:
+				ic->f = instr(teqi);
+				break;
+			case REGIMM_TNEI:
+				ic->f = instr(tnei);
+				break;
+			}
+
+			ic->arg[0] = (size_t)&cpu->cd.mips.gpr[rs];
+			ic->arg[1] = imm;
+			break;
+
 		default:if (!cpu->translation_readahead)
 				fatal("UNIMPLEMENTED regimm rt=%i\n", rt);
 			goto bad;
@@ -4753,7 +4870,7 @@ X(to_be_translated)
 		if (!has_warned && !cpu->translation_readahead) {
 			fatal("[ WARNING/NOTE: attempt to execute a 64-bit"
 			    " instruction on an emulated 32-bit processor; "
-			    "pc=0x%08"PRIx32" ]\n", (uint32_t)cpu->pc);
+			    "pc=0x%08" PRIx32 " ]\n", (uint32_t)cpu->pc);
 			has_warned = 1;
 		}
 		if (cpu->translation_readahead)
@@ -4770,4 +4887,3 @@ X(to_be_translated)
 #include "cpu_dyntrans.cc" 
 #undef	DYNTRANS_TO_BE_TRANSLATED_TAIL
 }
-
