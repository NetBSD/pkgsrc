$NetBSD: patch-plat_sun50iw1p1_sunxi__power.c,v 1.1 2019/02/20 17:04:13 martin Exp $

Fix power up sequence for pinebook display / eDP bridge.

--- plat/sun50iw1p1/sunxi_power.c.orig	2018-04-03 00:27:49.000000000 +0200
+++ plat/sun50iw1p1/sunxi_power.c	2019-02-19 14:39:16.148546954 +0100
@@ -266,6 +266,9 @@ static int pmic_setup(const char *dt_nam
 		ret = sunxi_pmic_read(0x12);
 		sunxi_pmic_write(0x12, ret | 0x10);
 
+		/* the ANX data sheet is rumored to say we need to wait for 2ms */
+		udelay(2000);
+
 		sunxi_pmic_write(0x1c, 0x0a); /* FLDO1 = HSIC = 1.2V */
 		ret = sunxi_pmic_read(0x13);
 		sunxi_pmic_write(0x13, ret | 0x4);
