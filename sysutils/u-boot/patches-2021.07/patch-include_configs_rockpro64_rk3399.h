$NetBSD: patch-include_configs_rockpro64_rk3399.h,v 1.1 2021/07/26 06:36:41 mrg Exp $

Add CONFIG_SCSI support.

--- include/configs/rockpro64_rk3399.h.orig	2021-04-26 17:53:51.000000000 -0700
+++ include/configs/rockpro64_rk3399.h	2021-05-22 16:57:19.869714755 -0700
@@ -17,4 +17,13 @@
 
 #define CONFIG_USB_OHCI_NEW
 #define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS     2
+
+#if defined(CONFIG_SCSI) && 0
+#define CONFIG_SCSI_AHCI
+#define CONFIG_SYS_SCSI_MAX_DEVICE	4
+#define CONFIG_SYS_SCSI_MAX_SCSI_ID	4
+#define CONFIG_SYS_SCSI_MAX_LUN		1
+#define CONFIG_SYS_SATA_MAX_DEVICE	4
+#endif
+
 #endif
