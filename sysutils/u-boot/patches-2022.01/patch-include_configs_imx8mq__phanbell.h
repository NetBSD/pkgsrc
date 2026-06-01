$NetBSD: patch-include_configs_imx8mq__phanbell.h,v 1.1 2026/06/01 08:56:16 rxg Exp $

Could not get FIT buffer of 592896 bytes
        check CONFIG_SYS_SPL_MALLOC_SIZE

--- include/configs/imx8mq_phanbell.h.orig	2026-05-28 09:02:01.159862213 +0000
+++ include/configs/imx8mq_phanbell.h
@@ -20,7 +20,7 @@
 #define CONFIG_SPL_BSS_START_ADDR      0x00180000
 #define CONFIG_SPL_BSS_MAX_SIZE        0x2000	/* 8 KB */
 #define CONFIG_SYS_SPL_MALLOC_START    0x42200000
-#define CONFIG_SYS_SPL_MALLOC_SIZE    0x80000	/* 512 KB */
+#define CONFIG_SYS_SPL_MALLOC_SIZE     0x100000	/* 1 MB */
 #define CONFIG_SYS_SPL_PTE_RAM_BASE    0x41580000
 
 /* malloc f used before GD_FLG_FULL_MALLOC_INIT set */
