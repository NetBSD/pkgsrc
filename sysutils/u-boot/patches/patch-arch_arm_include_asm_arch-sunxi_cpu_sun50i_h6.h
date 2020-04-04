$NetBSD: patch-arch_arm_include_asm_arch-sunxi_cpu_sun50i_h6.h,v 1.1 2020/04/04 15:20:35 thorpej Exp $

Define SUNXI_R_WDOG_BASE; used for an H6-specific workaround for a
broken watchdog timer which breaks reboot/reset.

--- arch/arm/include/asm/arch-sunxi/cpu_sun50i_h6.h.orig	2020-03-27 00:39:23.000000000 +0000
+++ arch/arm/include/asm/arch-sunxi/cpu_sun50i_h6.h
@@ -60,6 +60,7 @@
 #define SUNXI_RTC_BASE			0x07000000
 #define SUNXI_R_CPUCFG_BASE		0x07000400
 #define SUNXI_PRCM_BASE			0x07010000
+#define SUNXI_R_WDOG_BASE		0x07020400
 #define SUNXI_R_PIO_BASE		0x07022000
 #define SUNXI_R_UART_BASE		0x07080000
 #define SUNXI_R_TWI_BASE		0x07081400
