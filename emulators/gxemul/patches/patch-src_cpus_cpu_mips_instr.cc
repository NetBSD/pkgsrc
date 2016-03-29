$NetBSD: patch-src_cpus_cpu_mips_instr.cc,v 1.1 2016/03/29 19:03:07 mrg Exp $

implement trap with immediate instructions present in MIPS32.

--- src/cpus/cpu_mips_instr.cc.orig	2016-03-28 11:59:41.000000000 -0700
+++ src/cpus/cpu_mips_instr.cc	2016-03-28 12:04:07.000000000 -0700
@@ -1461,6 +1461,92 @@
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
@@ -4446,6 +4532,37 @@
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
