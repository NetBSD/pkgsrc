$NetBSD: patch-src_cpus_cpu__mips__instr__loadstore.cc,v 1.1 2021/01/16 16:49:36 skrll Exp $

--- src/cpus/cpu_mips_instr_loadstore.cc.orig	2021-01-16 16:33:52.314709654 +0000
+++ src/cpus/cpu_mips_instr_loadstore.cc
@@ -58,6 +58,30 @@ void LS_GENERIC_N(struct cpu *cpu, struc
 	/*  Check alignment:  */
 	if (addr & (LS_SIZE - 1)) {
 #if 1
+		uint64_t vaddr_vpn2=0, vaddr_asid=0;
+
+		int exc_model = cpu->cd.mips.cpu_type.exc_model;
+		struct mips_coproc *cp0 = cpu->cd.mips.coproc[0];
+
+		if (exc_model == EXC3K) {
+			vaddr_asid = (cp0->reg[COP0_ENTRYHI] &
+			    R2K3K_ENTRYHI_ASID_MASK) >>
+			    R2K3K_ENTRYHI_ASID_SHIFT;
+			vaddr_vpn2 = (addr & R2K3K_ENTRYHI_VPN_MASK) >>
+			    R2K3K_ENTRYHI_VPN_SHIFT;
+		} else {
+			vaddr_asid = cp0->reg[COP0_ENTRYHI] & ENTRYHI_ASID;
+
+			if (cpu->cd.mips.cpu_type.mmu_model == MMU10K) {
+				vaddr_vpn2 = (addr &
+				    ENTRYHI_VPN2_MASK_R10K) >>
+				    ENTRYHI_VPN2_SHIFT;
+			} else {
+				vaddr_vpn2 = (addr & ENTRYHI_VPN2_MASK) >>
+				    ENTRYHI_VPN2_SHIFT;
+			}
+		}
+
 		/*  Cause an address alignment exception:  */
 		mips_cpu_exception(cpu,
 #ifdef LS_LOAD
@@ -65,7 +89,7 @@ void LS_GENERIC_N(struct cpu *cpu, struc
 #else
 		    EXCEPTION_ADES,
 #endif
-		    0, addr, 0, 0, 0, 0);
+		    0, addr, 0, vaddr_vpn2, vaddr_asid, 0);
 #else
 		fatal("{ mips dyntrans alignment exception, size = %i,"
 		    " addr = %016"PRIx64", pc = %016"PRIx64" }\n", LS_SIZE,
