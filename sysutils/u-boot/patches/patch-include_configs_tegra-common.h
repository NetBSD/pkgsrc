$NetBSD: patch-include_configs_tegra-common.h,v 1.1 2017/09/23 17:33:12 jmcneill Exp $

--- include/configs/tegra-common.h.orig	2017-07-10 17:07:38.000000000 +0000
+++ include/configs/tegra-common.h
@@ -101,4 +101,7 @@
 #include <config_distro_defaults.h>
 #endif
 
+/* Override default uimg size limit */
+#define	CONFIG_SYS_BOOTM_LEN		0x1000000
+
 #endif /* _TEGRA_COMMON_H_ */
