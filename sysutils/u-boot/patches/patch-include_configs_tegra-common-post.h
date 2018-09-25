$NetBSD: patch-include_configs_tegra-common-post.h,v 1.1 2018/09/25 21:49:20 jmcneill Exp $

--- include/configs/tegra-common-post.h.orig	2018-05-07 15:32:36.000000000 +0000
+++ include/configs/tegra-common-post.h
@@ -90,6 +90,7 @@
 #define CONFIG_EXTRA_ENV_SETTINGS \
 	TEGRA_DEVICE_SETTINGS \
 	MEM_LAYOUT_ENV_SETTINGS \
+	"fdtfile=" CONFIG_DEFAULT_DEVICE_TREE ".dtb\0" \
 	"fdt_high=" FDT_HIGH "\0" \
 	"initrd_high=" INITRD_HIGH "\0" \
 	BOOTENV \
