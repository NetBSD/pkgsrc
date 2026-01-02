$NetBSD: patch-plugins_actor_pseudotoad__flower_notch.c,v 1.1 2026/01/02 12:30:19 adam Exp $

--- plugins/actor/pseudotoad_flower/notch.c.orig	2023-03-20 02:04:42.000000000 +0000
+++ plugins/actor/pseudotoad_flower/notch.c
@@ -26,12 +26,13 @@
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include "notch.h"
 
 NOTCH_FILTER *  init_notch(float cutoff) {
     NOTCH_FILTER * l=malloc(sizeof(NOTCH_FILTER));
-    float steep = 0.99;;
+    float steep = 0.99;
     float r = steep * 0.99609375;
     float f = cos(M_PI * cutoff / SAMPLING_RATE);
     l->cutoff = cutoff;
