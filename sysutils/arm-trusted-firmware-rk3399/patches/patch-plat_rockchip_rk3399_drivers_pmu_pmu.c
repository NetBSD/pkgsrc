$NetBSD: patch-plat_rockchip_rk3399_drivers_pmu_pmu.c,v 1.1 2020/02/22 11:55:36 mrg Exp $

pull in https://github.com/ARM-software/arm-trusted-firmware/commit/b4899041e5f0b8e8b388c6511b5233516b8785ec

 plat/rockchip: enable power domains of rk3399 before reset

 This patch fixes hangs that happen after soft resetting of rk3399.

 Signed-off-by: Piotr Szczepanik <piter75@gmail.com>
 Change-Id: If41b12ba1dfcb2ba937361b58eafd50bf5c483d4

with one additional change to force using the soft reset path,
as the gpio one does not seem to work.


--- plat/rockchip/rk3399/drivers/pmu/pmu.c.orig	2019-10-22 06:36:23.000000000 -0700
+++ plat/rockchip/rk3399/drivers/pmu/pmu.c	2020-02-22 03:31:50.759523535 -0800
@@ -400,6 +400,25 @@
 	clk_gate_con_restore();
 }
 
+void pmu_power_domains_on(void)
+{
+	clk_gate_con_disable();
+	pmu_set_power_domain(PD_VDU, pmu_pd_on);
+	pmu_set_power_domain(PD_VCODEC, pmu_pd_on);
+	pmu_set_power_domain(PD_RGA, pmu_pd_on);
+	pmu_set_power_domain(PD_IEP, pmu_pd_on);
+	pmu_set_power_domain(PD_EDP, pmu_pd_on);
+	pmu_set_power_domain(PD_GMAC, pmu_pd_on);
+	pmu_set_power_domain(PD_SDIOAUDIO, pmu_pd_on);
+	pmu_set_power_domain(PD_HDCP, pmu_pd_on);
+	pmu_set_power_domain(PD_ISP1, pmu_pd_on);
+	pmu_set_power_domain(PD_ISP0, pmu_pd_on);
+	pmu_set_power_domain(PD_VO, pmu_pd_on);
+	pmu_set_power_domain(PD_TCPD1, pmu_pd_on);
+	pmu_set_power_domain(PD_TCPD0, pmu_pd_on);
+	pmu_set_power_domain(PD_GPU, pmu_pd_on);
+}
+
 void rk3399_flush_l2_b(void)
 {
 	uint32_t wait_cnt = 0;
@@ -1504,7 +1523,7 @@
 
 	rst_gpio = plat_get_rockchip_gpio_reset();
 
-	if (rst_gpio) {
+	if (rst_gpio && 0) {
 		gpio_set_direction(rst_gpio->index, GPIO_DIR_OUT);
 		gpio_set_value(rst_gpio->index, rst_gpio->polarity);
 	} else {
