$NetBSD: patch-src_cpus_cpu__mips__instr.cc,v 1.1 2019/06/30 20:33:02 skrll Exp $

When emulating the MIPS DIV and DDIV instructions, check for divide
overflow instead of performing the overflowing divide on the host and
crashing the emulator.  This is needed to run recent versions of the
NetBSD test suite on an emulated MIPS system.

implement trap with immediate instructions present in MIPS32.

--- src/cpus/cpu_mips_instr.cc.orig	2019-06-29 16:17:02.938155374 +0000
+++ src/cpus/cpu_mips_instr.cc
@@ -1275,6 +1275,8 @@ X(divu)
 	uint32_t res, rem;
 	if (b == 0)
 		res = 0, rem = a;
+	else if (a == (int32_t)0x80000000U && b == -1)
+		res = 0, rem = 0;
 	else
 		res = a / b, rem = a - b*res;
 	cpu->cd.mips.lo = (int32_t)res;
@@ -1300,6 +1302,8 @@ X(ddivu)
 	uint64_t res, rem;
 	if (b == 0)
 		res = 0;
+	else if (a == (int64_t)0x8000000000000000ULL && b == -1)
+		res = 0;
 	else
 		res = a / b;
 	rem = a - b*res;
@@ -1465,6 +1469,92 @@ X(tne)
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
@@ -4478,6 +4568,37 @@ X(to_be_translated)
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
