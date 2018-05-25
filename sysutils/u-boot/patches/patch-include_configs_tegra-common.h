$NetBSD: patch-include_configs_tegra-common.h,v 1.2 2018/05/25 10:45:22 jmcneill Exp $

--- include/configs/tegra-common.h.orig	2018-05-07 15:32:36.000000000 +0000
+++ include/configs/tegra-common.h
@@ -92,4 +92,7 @@
 /* Misc utility code */
 #define CONFIG_BOUNCE_BUFFER
 
+/* Override default uimg size limit */
+#define	CONFIG_SYS_BOOTM_LEN		0x1000000
+
 #endif /* _TEGRA_COMMON_H_ */
