$NetBSD: patch-arch_arm_mach-rockchip_rk3399_rk3399.c,v 1.1 2021/07/26 06:36:41 mrg Exp $

adjusted by mrg to restrict to CONFIG_TARGET_PINEBOOK_PRO_RK3399.


Author: dhivael <dhivael.git@eno.space>
Date:   Sat Jan 11 15:04:46 2020 +0100

    rk3399: light pinebook power and standby leds during early boot
    
    this is a hack, but it works for now.


--- arch/arm/mach-rockchip/rk3399/rk3399.c.orig	2021-04-05 08:03:29.000000000 -0700
+++ arch/arm/mach-rockchip/rk3399/rk3399.c	2021-05-08 00:46:34.547804408 -0700
@@ -20,6 +20,8 @@
 #include <asm/arch-rockchip/hardware.h>
 #include <linux/bitops.h>
 #include <power/regulator.h>
+#include <dt-bindings/gpio/gpio.h>
+#include <dt-bindings/pinctrl/rockchip.h>
 
 DECLARE_GLOBAL_DATA_PTR;
 
@@ -122,6 +124,9 @@
 	struct rk3399_pmugrf_regs * const pmugrf = (void *)PMUGRF_BASE;
 	struct rockchip_gpio_regs * const gpio = (void *)GPIO0_BASE;
 #endif
+#ifdef CONFIG_TARGET_PINEBOOK_PRO_RK3399
+	struct rockchip_gpio_regs * const gpio = (void *)GPIO0_BASE;
+#endif
 
 #if defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff180000)
 	/* Enable early UART0 on the RK3399 */
@@ -154,6 +159,17 @@
 	spl_gpio_set_pull(&pmugrf->gpio0_p, GPIO(BANK_B, 4), GPIO_PULL_NORMAL);
 #endif /* CONFIG_TARGET_CHROMEBOOK_BOB */
 
+#ifdef CONFIG_TARGET_PINEBOOK_PRO_RK3399
+
+	{
+		// set GPIO0_A2/B3 to GPIO_ACTIVE_HIGH
+		// set GPIO0_A2/B3 to OUTPUT
+		int mask = (1UL << RK_PA2) | (1UL << RK_PB3);
+		setbits_le32(&gpio->swport_dr, mask);
+		setbits_le32(&gpio->swport_ddr, mask);
+	}
+#endif
+
 	/* Enable early UART2 channel C on the RK3399 */
 	rk_clrsetreg(&grf->gpio4c_iomux,
 		     GRF_GPIO4C3_SEL_MASK,
