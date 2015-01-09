$NetBSD: patch-src-post-planar-eq2.c,v 1.7 2015/01/09 22:59:43 wiz Exp $

First chunk:
https://bugs.xine-project.org/show_bug.cgi?id=556

Rest:
https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/eq2.c.orig	2014-06-09 16:08:42.000000000 +0000
+++ src/post/planar/eq2.c
@@ -125,11 +125,11 @@ void affine_1d_MMX (eq2_param_t *par, un
   dstep = dstride - w;
 
   asm volatile (
-    "movq (%0), %%mm3 \n\t"
-    "movq (%1), %%mm4 \n\t"
+    "movq %0, %%mm3 \n\t"
+    "movq %1, %%mm4 \n\t"
     "pxor %%mm0, %%mm0 \n\t"
     :
-    : "g" (brvec), "g" (contvec)
+    : "m" (brvec), "m" (contvec)
   );
 
   while (h-- > 0) {
@@ -293,19 +293,26 @@ typedef struct eq2_parameters_s {
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
 
