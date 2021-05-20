$NetBSD: patch-signpr__cmf2.c,v 1.1 2021/05/20 19:24:15 nia Exp $

- include missing header for strlen().
- overflow fixes from Debian:
  https://sources.debian.org/patches/gramofile/1.6-12/20-overflow-fixes.patch/
  Patch by James Tappin <james@xena.uklinux.net>

--- signpr_cmf2.c.orig	2000-11-26 00:56:00.000000000 +0000
+++ signpr_cmf2.c
@@ -32,6 +32,7 @@
 #include "helpline.h"
 #include "yesnowindow.h"
 #endif
+#include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <math.h>
@@ -652,19 +653,25 @@ cond_median2_highpass (long offset, long
 
   /* Should be /64, but the signal is extremely soft, so divide by less to
      get more quantization levels (more accurate) */
-  sum.left /= 10;
-  sum.right /= 10;
+  sum.left /= 4;
+  sum.right /= 4;
 #endif
 
-  if (sum.left < 32767)
-    sample.left = sum.left;
-  else
+  if (sum.left > 32767)
     sample.left = 32767;
-
-  if (sum.right < 32767)
-    sample.right = sum.right;
+  else if (sum.left < -32768)
+    sample.left = -32768;
   else
+    sample.left = sum.left;
+
+
+  if (sum.right > 32767)
     sample.right = 32767;
+  else if (sum.right < -32768)
+    sample.right = -32768;
+  else 
+    sample.right = sum.right;
+
 
   return sample;
 }
@@ -768,6 +775,9 @@ cond_median2_gate (long offset, long off
     b_t.left;
   if (i > 32767)
     i = 32767;
+  else if (i < -32768)
+    i = -32768;
+
   returnval.left = i;
 
   i = (labs (w_t.right - b_t.right) * 1000)
@@ -775,6 +785,8 @@ cond_median2_gate (long offset, long off
     b_t.right;
   if (i > 32767)
     i = 32767;
+  else if (i < -32768)
+    i = -32768;
   returnval.right = i;
 
   return returnval;
