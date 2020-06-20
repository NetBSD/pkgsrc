$NetBSD: patch-include_configs_mt7623.h,v 1.2 2020/06/20 17:42:34 thorpej Exp $

Set the bootm_size, kernel_addr_r, fdt_addr_r, scriptaddr, pxefile_addr_r,
ramdisk_addr_r, and fdtfile environment varibles.

--- include/configs/mt7623.h.orig	2020-04-13 15:02:18.000000000 +0000
+++ include/configs/mt7623.h	2020-06-20 17:33:23.538928996 +0000
@@ -42,14 +42,39 @@
 #define MMC_SUPPORTS_TUNING
 
 /* DRAM */
+#define SDRAM_OFFSET(x) 0x8##x
 #define CONFIG_SYS_SDRAM_BASE		0x80000000
 
 /* This is needed for kernel booting */
 #define FDT_HIGH			"fdt_high=0xac000000\0"
 
+/*
+ * 128M RAM (256M minimum minus 64MB heap + 64MB for u-boot, stack, fb, etc.
+ * 32M uncompressed kernel, 16M compressed kernel, 1M fdt,
+ * 1M script, 1M pxe and the ramdisk at the end.
+ */
+#define BOOTM_SIZE     __stringify(0xa000000)
+#define KERNEL_ADDR_R  __stringify(SDRAM_OFFSET(4000000))
+#define FDT_ADDR_R     __stringify(SDRAM_OFFSET(5000000))
+#define SCRIPT_ADDR_R  __stringify(SDRAM_OFFSET(5100000))
+#define PXEFILE_ADDR_R __stringify(SDRAM_OFFSET(5200000))
+#define RAMDISK_ADDR_R __stringify(SDRAM_OFFSET(5300000))
+
+#define MEM_LAYOUT_ENV_SETTINGS \
+	"bootm_size=" BOOTM_SIZE "\0" \
+	"kernel_addr_r=" KERNEL_ADDR_R "\0" \
+	"fdt_addr_r=" FDT_ADDR_R "\0" \
+	"scriptaddr=" SCRIPT_ADDR_R "\0" \
+	"pxefile_addr_r=" PXEFILE_ADDR_R "\0" \
+	"ramdisk_addr_r=" RAMDISK_ADDR_R "\0"
+
+#define FDTFILE CONFIG_DEFAULT_DEVICE_TREE ".dtb"
+
 /* Extra environment variables */
 #define CONFIG_EXTRA_ENV_SETTINGS	\
-	FDT_HIGH
+	FDT_HIGH \
+	MEM_LAYOUT_ENV_SETTINGS \
+	"fdtfile=" FDTFILE "\0"
 
 /* Ethernet */
 #define CONFIG_IPADDR			192.168.1.1
