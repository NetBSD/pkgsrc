$NetBSD: patch-drivers_video_sunxi_sunxi__display.c,v 1.1 2017/12/18 23:27:14 jmcneill Exp $

Align FB address to 8KB for NetBSD/arm.

--- drivers/video/sunxi/sunxi_display.c.orig	2017-11-14 01:08:06.000000000 +0000
+++ drivers/video/sunxi/sunxi_display.c
@@ -1186,7 +1186,7 @@ void *video_hw_init(void)
 	/* We want to keep the fb_base for simplefb page aligned, where as
 	 * the sunxi dma engines will happily accept an unaligned address. */
 	if (overscan_offset)
-		sunxi_display.fb_size += 0x1000;
+		sunxi_display.fb_size += 0x2000;
 
 	if (sunxi_display.fb_size > CONFIG_SUNXI_MAX_FB_SIZE) {
 		printf("Error need %dkB for fb, but only %dkB is reserved\n",
@@ -1208,8 +1208,8 @@ void *video_hw_init(void)
 	fb_dma_addr = gd->fb_base - CONFIG_SYS_SDRAM_BASE;
 	sunxi_display.fb_addr = gd->fb_base;
 	if (overscan_offset) {
-		fb_dma_addr += 0x1000 - (overscan_offset & 0xfff);
-		sunxi_display.fb_addr += (overscan_offset + 0xfff) & ~0xfff;
+		fb_dma_addr += 0x2000 - (overscan_offset & 0x1fff);
+		sunxi_display.fb_addr += (overscan_offset + 0x1fff) & ~0x1fff;
 		memset((void *)gd->fb_base, 0, sunxi_display.fb_size);
 		flush_cache(gd->fb_base, sunxi_display.fb_size);
 	}
