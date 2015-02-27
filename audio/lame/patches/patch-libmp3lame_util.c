$NetBSD: patch-libmp3lame_util.c,v 1.1 2015/02/27 19:49:16 snj Exp $

https://bugs.debian.org/778529

--- libmp3lame/util.c.orig	2012-01-10 11:55:55.000000000 -0800
+++ libmp3lame/util.c	2015-02-27 11:25:26.000000000 -0800
@@ -26,6 +26,7 @@
 # include <config.h>
 #endif
 
+#include <float.h>
 #include "lame.h"
 #include "machine.h"
 #include "encoder.h"
@@ -544,7 +545,7 @@ fill_buffer_resample(lame_internal_flags
     if (bpc > BPC)
         bpc = BPC;
 
-    intratio = (fabs(resample_ratio - floor(.5 + resample_ratio)) < .0001);
+    intratio = (fabs(resample_ratio - floor(.5 + resample_ratio)) < FLT_EPSILON);
     fcn = 1.00 / resample_ratio;
     if (fcn > 1.00)
         fcn = 1.00;
