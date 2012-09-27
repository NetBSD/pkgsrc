$NetBSD: patch-src-post-planar-eq2.c,v 1.2 2012/09/27 10:28:14 apb Exp $

In affine_1d_MMX(), move the initialisation of %mm3 and %mm4 registers
into a separate asm statement, to give the compiler more freedom
for register allocation.  Fixes a problem with gcc-4.5.4 on NetBSD/i386
in which gcc complained:

eq2.c: In function 'affine_1d_MMX':
eq2.c:128:5: error: can't find a register in class 'GENERAL_REGS' while reloading 'asm'
eq2.c:128:5: error: 'asm' operand has impossible constraints

--- src/post/planar/eq2.c.orig	2012-02-05 19:17:02.000000000 +0000
+++ src/post/planar/eq2.c
@@ -126,8 +126,13 @@ void affine_1d_MMX (eq2_param_t *par, un
 
   while (h-- > 0) {
     asm volatile (
-      "movq (%5), %%mm3 \n\t"
-      "movq (%6), %%mm4 \n\t"
+      "movq (%0), %%mm3 \n\t"
+      "movq (%1), %%mm4 \n\t"
+      :
+      : "r" (brvec), "r" (contvec)
+      :
+    );
+    asm volatile (
       "pxor %%mm0, %%mm0 \n\t"
       "movl %4, %%eax\n\t"
       ASMALIGN(4)
@@ -149,7 +154,7 @@ void affine_1d_MMX (eq2_param_t *par, un
       "decl %%eax \n\t"
       "jnz 1b \n\t"
       : "=r" (src), "=r" (dst)
-      : "0" (src), "1" (dst), "r" (w >> 3), "r" (brvec), "r" (contvec)
+      : "0" (src), "1" (dst), "r" (w >> 3)
       : "%eax"
     );
 
@@ -288,19 +293,26 @@ typedef struct eq2_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( eq2_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, gamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, gamma, NULL, 0, 5, 0,
             "gamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, brightness, NULL, -1, 1, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, brightness, NULL, -1, 1, 0,
             "brightness" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, contrast, NULL, 0, 2, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, contrast, NULL, 0, 2, 0,
             "contrast" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, saturation, NULL, 0, 2, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, saturation, NULL, 0, 2, 0,
             "saturation" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, rgamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, rgamma, NULL, 0, 5, 0,
             "rgamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, ggamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, ggamma, NULL, 0, 5, 0,
             "ggamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, bgamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, bgamma, NULL, 0, 5, 0,
             "bgamma" )
 END_PARAM_DESCR( param_descr )
 
