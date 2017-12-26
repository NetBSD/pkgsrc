$NetBSD: patch-Source_LibWebP_src_dsp_dsp.yuv_mips_dsp_r2.c,v 1.1 2017/12/26 11:55:01 he Exp $

Adapt to newer C++ where R"some string" has new meaning.

--- Source/LibWebP/./src/dsp/dsp.yuv_mips_dsp_r2.c.orig	2015-02-20 02:34:38.000000000 +0000
+++ Source/LibWebP/./src/dsp/dsp.yuv_mips_dsp_r2.c
@@ -35,7 +35,7 @@
   "addu             %[temp2],   %[temp2],       %[temp3]        \n\t"          \
   "addu             %[temp4],   %[temp4],       %[t_con_8]      \n\t"          \
 
-#define ROW_FUNC_PART_2(R, G, B, K)                                            \
+#define ROW_FUNC_PART_2(Red, G, B, K)                                          \
   "addu             %[temp5],   %[temp0],       %[temp1]        \n\t"          \
   "subu             %[temp6],   %[temp0],       %[temp2]        \n\t"          \
   "addu             %[temp7],   %[temp0],       %[temp4]        \n\t"          \
@@ -54,7 +54,7 @@
   "srl              %[temp5],   %[temp5],       24              \n\t"          \
   "srl              %[temp6],   %[temp6],       24              \n\t"          \
   "srl              %[temp7],   %[temp7],       24              \n\t"          \
-  "sb               %[temp5],   "#R"(%[dst])                    \n\t"          \
+  "sb               %[temp5],   "#Red"(%[dst])                  \n\t"          \
   "sb               %[temp6],   "#G"(%[dst])                    \n\t"          \
   "sb               %[temp7],   "#B"(%[dst])                    \n\t"          \
 
