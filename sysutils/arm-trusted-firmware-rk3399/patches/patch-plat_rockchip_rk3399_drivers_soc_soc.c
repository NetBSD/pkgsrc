$NetBSD: patch-plat_rockchip_rk3399_drivers_soc_soc.c,v 1.1 2020/02/22 11:55:36 mrg Exp $

pull in https://github.com/ARM-software/arm-trusted-firmware/commit/b4899041e5f0b8e8b388c6511b5233516b8785ec

 plat/rockchip: enable power domains of rk3399 before reset

 This patch fixes hangs that happen after soft resetting of rk3399.

 Signed-off-by: Piotr Szczepanik <piter75@gmail.com>
 Change-Id: If41b12ba1dfcb2ba937361b58eafd50bf5c483d4

with one additional change to force using the soft reset path,
as the gpio one does not seem to work.


--- plat/rockchip/rk3399/drivers/soc/soc.c.orig	2020-02-22 02:30:58.094221102 -0800
+++ plat/rockchip/rk3399/drivers/soc/soc.c	2020-02-22 02:31:04.989130511 -0800
@@ -17,6 +17,7 @@
 #include <dram.h>
 #include <m0_ctl.h>
 #include <plat_private.h>
+#include <pmu.h>
 #include <rk3399_def.h>
 #include <secure.h>
 #include <soc.h>
@@ -327,6 +328,7 @@
 
 void __dead2 soc_global_soft_reset(void)
 {
+	pmu_power_domains_on();
 	set_pll_slow_mode(VPLL_ID);
 	set_pll_slow_mode(NPLL_ID);
 	set_pll_slow_mode(GPLL_ID);
