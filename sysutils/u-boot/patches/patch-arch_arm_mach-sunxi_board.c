$NetBSD: patch-arch_arm_mach-sunxi_board.c,v 1.1 2020/04/04 15:20:35 thorpej Exp $

H6-specific workaround for a broken watchdog timer which breaks
reboot/reset.  Use R_WDOG instead.

--- arch/arm/mach-sunxi/board.c.orig	2020-03-27 00:42:23.478886897 +0000
+++ arch/arm/mach-sunxi/board.c	2020-03-27 00:46:14.553859057 +0000
@@ -287,8 +287,14 @@ void reset_cpu(ulong addr)
 		writel(WDT_MODE_RESET_EN | WDT_MODE_EN, &wdog->mode);
 	}
 #elif defined(CONFIG_SUNXI_GEN_SUN6I) || defined(CONFIG_MACH_SUN50I_H6)
+#if defined(CONFIG_MACH_SUN50I_H6)
+	/* WDOG is broken for H6 use the R_WDOG instead */
+	static const struct sunxi_wdog *wdog =
+		 (struct sunxi_wdog *)SUNXI_R_WDOG_BASE;
+#else
 	static const struct sunxi_wdog *wdog =
 		 ((struct sunxi_timer_reg *)SUNXI_TIMER_BASE)->wdog;
+#endif
 
 	/* Set the watchdog for its shortest interval (.5s) and wait */
 	writel(WDT_CFG_RESET, &wdog->cfg);
