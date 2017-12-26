$NetBSD: patch-Source_LibWebP_src_dsp_dsp.upsampling_mips_dsp_r2.c,v 1.1 2017/12/26 11:55:01 he Exp $

Adapt to newer C++ where R"some string" has new meaning.

--- Source/LibWebP/./src/dsp/dsp.upsampling_mips_dsp_r2.c.orig	2015-02-20 02:34:36.000000000 +0000
+++ Source/LibWebP/./src/dsp/dsp.upsampling_mips_dsp_r2.c
@@ -21,29 +21,29 @@
 
 #if !defined(WEBP_YUV_USE_TABLE)
 
-#define YUV_TO_RGB(Y, U, V, R, G, B) do {                                      \
+#define YUV_TO_RGB(Y, U, V, Red, G, B) do {                                      \
     const int t1 = kYScale * Y;                                                \
     const int t2 = kVToG * V;                                                  \
-    R = kVToR * V;                                                             \
+    Red = kVToR * V;                                                           \
     G = kUToG * U;                                                             \
     B = kUToB * U;                                                             \
-    R = t1 + R;                                                                \
+    Red = t1 + Red;                                                            \
     G = t1 - G;                                                                \
     B = t1 + B;                                                                \
-    R = R + kRCst;                                                             \
+    Red = Red + kRCst;                                                         \
     G = G - t2 + kGCst;                                                        \
     B = B + kBCst;                                                             \
     __asm__ volatile (                                                         \
-      "shll_s.w         %["#R"],      %["#R"],        9              \n\t"     \
+      "shll_s.w         %["#Red"],    %["#Red"],      9              \n\t"     \
       "shll_s.w         %["#G"],      %["#G"],        9              \n\t"     \
       "shll_s.w         %["#B"],      %["#B"],        9              \n\t"     \
-      "precrqu_s.qb.ph  %["#R"],      %["#R"],        $zero          \n\t"     \
+      "precrqu_s.qb.ph  %["#Red"],    %["#Red"],      $zero          \n\t"     \
       "precrqu_s.qb.ph  %["#G"],      %["#G"],        $zero          \n\t"     \
       "precrqu_s.qb.ph  %["#B"],      %["#B"],        $zero          \n\t"     \
-      "srl              %["#R"],      %["#R"],        24             \n\t"     \
+      "srl              %["#Red"],    %["#Red"],      24             \n\t"     \
       "srl              %["#G"],      %["#G"],        24             \n\t"     \
       "srl              %["#B"],      %["#B"],        24             \n\t"     \
-      : [R]"+r"(R), [G]"+r"(G), [B]"+r"(B)                                     \
+      : [Red]"+r"(Red), [G]"+r"(G), [B]"+r"(B)                                 \
       :                                                                        \
     );                                                                         \
   } while (0)
