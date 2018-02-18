$NetBSD: patch-include_configs_sunxi-common.h,v 1.2 2018/02/18 12:27:20 jmcneill Exp $

--- include/configs/sunxi-common.h.orig	2018-01-23 06:50:34.000000000 +0000
+++ include/configs/sunxi-common.h
@@ -284,6 +284,10 @@ extern int soft_i2c_gpio_scl;
 
 #endif /* CONFIG_VIDEO_SUNXI */
 
+#ifdef CONFIG_VIDEO_DE2
+#define CONFIG_VIDEO_DT_SIMPLEFB
+#endif
+
 /* Ethernet support */
 #ifdef CONFIG_SUN4I_EMAC
 #define CONFIG_PHY_ADDR		1
