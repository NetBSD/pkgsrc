$NetBSD: patch-drivers_video_sunxi_sunxi__de2.c,v 1.1 2017/09/10 17:00:41 jmcneill Exp $

sunxi: setup simplefb for Allwinner DE2

Obtained from https://patchwork.ozlabs.org/patch/759922/

--- drivers/video/sunxi/sunxi_de2.c.orig	2017-09-01 04:53:54.000000000 +0000
+++ drivers/video/sunxi/sunxi_de2.c
@@ -11,6 +11,8 @@
 #include <display.h>
 #include <dm.h>
 #include <edid.h>
+#include <fdtdec.h>
+#include <fdt_support.h>
 #include <video.h>
 #include <asm/global_data.h>
 #include <asm/io.h>
@@ -310,3 +312,82 @@ U_BOOT_DRIVER(sunxi_de2) = {
 U_BOOT_DEVICE(sunxi_de2) = {
 	.name = "sunxi_de2"
 };
+
+/*
+ * Simplefb support.
+ */
+#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_VIDEO_DT_SIMPLEFB)
+int sunxi_simplefb_setup(void *blob)
+{
+	struct udevice *de2, *hdmi;
+	struct video_priv *de2_priv;
+	struct video_uc_platdata *de2_plat;
+	int mux;
+	int offset, ret;
+	u64 start, size;
+	const char *pipeline = NULL;
+
+	debug("Setting up simplefb\n");
+
+	if (IS_ENABLED(CONFIG_MACH_SUNXI_H3_H5))
+		mux = 0;
+	else
+		mux = 1;
+
+	/* Skip simplefb setting if DE2 / HDMI is not present */
+	ret = uclass_find_device_by_name(UCLASS_VIDEO,
+					 "sunxi_de2", &de2);
+	if (ret) {
+		debug("DE2 not present\n");
+		return 0;
+	}
+
+	ret = uclass_find_device_by_name(UCLASS_DISPLAY,
+					 "sunxi_lcd", &hdmi);
+	if (ret) {
+		debug("HDMI not present\n");
+		return 0;
+	}
+
+	if (mux == 0)
+		pipeline = "mixer0-lcd0-hdmi";
+	else
+		pipeline = "mixer1-lcd1-hdmi";
+
+	de2_priv = dev_get_uclass_priv(de2);
+	de2_plat = dev_get_uclass_platdata(de2);
+
+	/* Find a prefilled simpefb node, matching out pipeline config */
+	offset = fdt_node_offset_by_compatible(blob, -1,
+					       "allwinner,simple-framebuffer");
+	while (offset >= 0) {
+		ret = fdt_stringlist_search(blob, offset, "allwinner,pipeline",
+					    pipeline);
+		if (ret == 0)
+			break;
+		offset = fdt_node_offset_by_compatible(blob, offset,
+					       "allwinner,simple-framebuffer");
+	}
+	if (offset < 0) {
+		eprintf("Cannot setup simplefb: node not found\n");
+		return 0; /* Keep older kernels working */
+	}
+
+	start = gd->bd->bi_dram[0].start;
+	size = de2_plat->base - start;
+	ret = fdt_fixup_memory_banks(blob, &start, &size, 1);
+	if (ret) {
+		eprintf("Cannot setup simplefb: Error reserving memory\n");
+		return ret;
+	}
+
+	ret = fdt_setup_simplefb_node(blob, offset, de2_plat->base,
+			de2_priv->xsize, de2_priv->ysize,
+			(1 << de2_priv->bpix) / 8 * de2_priv->xsize,
+			"x8r8g8b8");
+	if (ret)
+		eprintf("Cannot setup simplefb: Error setting properties\n");
+
+	return ret;
+}
+#endif /* CONFIG_OF_BOARD_SETUP && CONFIG_VIDEO_DT_SIMPLEFB */
