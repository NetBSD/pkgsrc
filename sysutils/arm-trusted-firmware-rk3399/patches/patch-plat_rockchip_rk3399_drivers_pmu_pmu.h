$NetBSD: patch-plat_rockchip_rk3399_drivers_pmu_pmu.h,v 1.1 2020/02/22 11:55:36 mrg Exp $

pull in https://github.com/ARM-software/arm-trusted-firmware/commit/b4899041e5f0b8e8b388c6511b5233516b8785ec

 plat/rockchip: enable power domains of rk3399 before reset

 This patch fixes hangs that happen after soft resetting of rk3399.

 Signed-off-by: Piotr Szczepanik <piter75@gmail.com>
 Change-Id: If41b12ba1dfcb2ba937361b58eafd50bf5c483d4

with one additional change to force using the soft reset path,
as the gpio one does not seem to work.


--- plat/rockchip/rk3399/drivers/pmu/pmu.h.orig	2019-10-22 06:36:23.000000000 -0700
+++ plat/rockchip/rk3399/drivers/pmu/pmu.h	2020-02-22 02:32:31.695012124 -0800
@@ -136,5 +136,6 @@
 extern uint32_t clst_warmboot_data[PLATFORM_CLUSTER_COUNT];
 
 extern void sram_func_set_ddrctl_pll(uint32_t pll_src);
+void pmu_power_domains_on(void);
 
 #endif /* PMU_H */
