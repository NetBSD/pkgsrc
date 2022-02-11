$NetBSD: patch-arch_arm_lib_interrupts__64.c,v 1.1 2022/02/11 21:46:14 mrg Exp $

u-boot-rockpro64: fix broken PCI config space handling:

- Program bus number into the ECAM decoder for each access
- Use type 1 PCI config cycles for config spaces behind bridge
- Add a platform specific hack to the synchronous exception handler
  to deal with PCI-e subsystem triggering data aborts when probing
  nonexistent PCI devices.
- properly delay after deasserting reset for downstream devices to
  have time to initialize.

Allows booting from PCI devices behind bridges and probing
devices other than 0:0:0 and 1:0:0.

--- arch/arm/lib/interrupts_64.c.orig	2021-07-05 15:11:28.000000000 +0000
+++ arch/arm/lib/interrupts_64.c
@@ -111,11 +111,26 @@ void do_bad_error(struct pt_regs *pt_reg
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
