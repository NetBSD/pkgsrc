$NetBSD: patch-roms_qemu-palcode_hwrpb.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Add definitions for the Console Terminal Block portion of the HWRPB.

--- roms/qemu-palcode/hwrpb.h.orig	2020-10-03 23:04:51.494017689 +0000
+++ roms/qemu-palcode/hwrpb.h	2020-10-03 23:06:34.713833960 +0000
@@ -146,6 +146,65 @@ struct crb_struct {
 	struct vf_map_struct map[1];
 };
 
+struct ctb_struct {
+	unsigned long type;
+	unsigned long unit;
+	unsigned long res0;
+	unsigned long len;
+	unsigned long ipl;
+	unsigned long tintr_vec;
+	unsigned long rintr_vec;
+	unsigned long term_type;
+	unsigned long keybd_type;
+	unsigned long keybd_trans;
+	unsigned long keybd_map;
+	unsigned long keybd_state;
+	unsigned long keybd_last;
+	unsigned long font_us;
+	unsigned long font_mcs;
+	unsigned long font_width;
+	unsigned long font_height;
+	unsigned long mon_width;
+	unsigned long mon_height;
+	unsigned long dpi;
+	unsigned long planes;
+	unsigned long cur_width;
+	unsigned long cur_height;
+	unsigned long head_cnt;
+	unsigned long opwindow;
+	unsigned long head_offset;
+	unsigned long putchar;
+	unsigned long io_state;
+	unsigned long listen_state;
+	unsigned long xaddr;
+	unsigned long turboslot;
+	unsigned long server_off;
+	unsigned long line_off;
+	unsigned char csd;
+};
+
+#define	CTB_NONE	0x00
+#define	CTB_PRINTERPORT	0x02
+#define	CTB_GRAPHICS	0x03
+#define	CTB_TYPE4	0x04
+
+/*
+ * Format of the Console Terminal Block Type 4 `turboslot' field:
+ *
+ *  63                   40 39       32 31     24 23      16 15   8 7    0
+ *  |      reserved        |  channel  |  hose   | bus type |  bus | slot|
+ */
+#define	CTB_TURBOSLOT_CHANNEL(x)	(((x) >> 32) & 0xff)
+#define	CTB_TURBOSLOT_HOSE(x)		(((x) >> 24) & 0xff)
+#define	CTB_TURBOSLOT_TYPE(x)		(((x) >> 16) & 0xff)
+#define	CTB_TURBOSLOT_BUS(x)		(((x) >> 8) & 0xff)
+#define	CTB_TURBOSLOT_SLOT(x)		((x) & 0xff)
+
+#define	CTB_TURBOSLOT_TYPE_TC           0       /* TURBOchannel */
+#define	CTB_TURBOSLOT_TYPE_ISA          1       /* ISA */
+#define	CTB_TURBOSLOT_TYPE_EISA         2       /* EISA */
+#define	CTB_TURBOSLOT_TYPE_PCI          3       /* PCI */
+
 struct memclust_struct {
 	unsigned long start_pfn;
 	unsigned long numpages;
