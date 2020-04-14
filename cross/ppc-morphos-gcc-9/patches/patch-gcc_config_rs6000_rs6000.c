$NetBSD: patch-gcc_config_rs6000_rs6000.c,v 1.1 2020/04/14 22:02:21 js Exp $

Patch by Harry Sintonen.

--- gcc/config/rs6000/rs6000.c.orig	2020-02-09 13:46:53.000000000 +0000
+++ gcc/config/rs6000/rs6000.c
@@ -26840,6 +26840,12 @@ rs6000_components_for_bb (basic_block bb
       || bitmap_bit_p (kill, LR_REGNO))
     bitmap_set_bit (components, 0);
 
+#ifdef TARGET_BASEREL
+  /* Always mark LR saving to occur before basic_block if "saveds" function */
+  if (TARGET_BASEREL && info->baserel_save_p)
+    bitmap_set_bit (components, 0);
+#endif
+
   /* The TOC save.  */
   if (bitmap_bit_p (in, TOC_REGNUM)
       || bitmap_bit_p (gen, TOC_REGNUM)
