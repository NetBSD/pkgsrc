$NetBSD: patch-arch_arm_lib_interrupts__64.c,v 1.1 2021/07/27 20:47:35 tnn Exp $

backport PCIe fixes from sysutils/u-boot-rockpro64

--- arch/arm/lib/interrupts_64.c.orig	2020-04-15 17:13:47.000000000 +0000
+++ arch/arm/lib/interrupts_64.c
@@ -107,11 +107,26 @@ void do_bad_error(struct pt_regs *pt_reg
 	panic("Resetting CPU ...\n");
 }
 
+#ifdef CONFIG_ROCKCHIP_RK3399
+extern volatile int rockchip_pcie_expect_data_abort;
+extern volatile int rockchip_pcie_got_data_abort;
+#endif
 /*
  * do_sync handles the Synchronous Abort exception.
  */
 void do_sync(struct pt_regs *pt_regs, unsigned int esr)
 {
+#ifdef CONFIG_ROCKCHIP_RK3399
+	if ((esr >> 26) == 0x25 && rockchip_pcie_expect_data_abort) {
+		/*
+		 * Data Abort taken without a change in Exception level.
+		 * This happens when probing nonexistent PCI-e devices.
+		 */
+		rockchip_pcie_got_data_abort = 1;
+		pt_regs->elr += 4; /* skip faulting insn */
+		return;
+	}
+#endif
 	efi_restore_gd();
 	printf("\"Synchronous Abort\" handler, esr 0x%08x\n", esr);
 	show_regs(pt_regs);
