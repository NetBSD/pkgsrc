$NetBSD: patch-gcc_common_config_arm_arm-common.c,v 1.1 2018/06/17 19:50:52 maya Exp $

use dwarf2 if requested, netbsd/arm uses this.

--- gcc/common/config/arm/arm-common.c.orig	2017-01-11 14:39:00.884692000 +0000
+++ gcc/common/config/arm/arm-common.c
@@ -49,6 +49,9 @@ arm_except_unwind_info (struct gcc_optio
     return UI_SJLJ;
 #endif
 
+  if (ARM_DWARF_UNWIND_TABLES)
+    return UI_DWARF2;
+
   /* If not using ARM EABI unwind tables... */
   if (ARM_UNWIND_INFO)
     {
