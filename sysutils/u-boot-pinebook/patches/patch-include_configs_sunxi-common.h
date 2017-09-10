$NetBSD: patch-include_configs_sunxi-common.h,v 1.1 2017/09/10 17:00:41 jmcneill Exp $

sunxi: setup simplefb for Allwinner DE2

Obtained from https://patchwork.ozlabs.org/patch/759922/

--- include/configs/sunxi-common.h.orig	2017-07-10 17:07:38.000000000 +0000
+++ include/configs/sunxi-common.h
@@ -293,6 +293,10 @@ extern int soft_i2c_gpio_scl;
 
 #endif /* CONFIG_VIDEO */
 
+#ifdef CONFIG_VIDEO_DE2
+#define CONFIG_VIDEO_DT_SIMPLEFB
+#endif
+
 /* Ethernet support */
 #ifdef CONFIG_SUNXI_EMAC
 #define CONFIG_PHY_ADDR		1
