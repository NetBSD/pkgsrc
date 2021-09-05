$NetBSD: patch-src_cpus_cpu__arm.c,v 1.1 2021/09/05 07:27:13 skrll Exp $

--- src/cpus/cpu_arm.c.orig	2021-09-05 05:56:14.113306233 +0000
+++ src/cpus/cpu_arm.c
@@ -158,13 +158,17 @@ int arm_cpu_new(struct cpu *cpu, struct 
 		cpu->cd.arm.coproc[14] = arm_coproc_xscale_14;
 
 	/*
-	 *  NOTE/TODO: Ugly hack for OpenFirmware emulation:
+	 *  OLD: Ugly hack for OpenFirmware emulation:
+	 *
+	 *  Move this to the end of corresponding machine initialization
+	 *  code.
+	 *
+	 *	if (cpu->machine->prom_emulation) {
+	 *		cpu->cd.arm.of_emul_addr = cpu->machine->physical_ram_in_mb
+	 *		    * 1048576 - 8;
+	 *		store_32bit_word(cpu, cpu->cd.arm.of_emul_addr, 0xef8c64be);
+	 *	}
 	 */
-	if (cpu->machine->prom_emulation) {
-		cpu->cd.arm.of_emul_addr = cpu->machine->physical_ram_in_mb
-		    * 1048576 - 8;
-		store_32bit_word(cpu, cpu->cd.arm.of_emul_addr, 0xef8c64be);
-	}
 
 	cpu->cd.arm.flags = cpu->cd.arm.cpsr >> 28;
 
