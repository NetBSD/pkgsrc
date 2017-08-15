$NetBSD: patch-libfaac_quantize.c,v 1.1 2017/08/15 13:55:17 adam Exp $

Fix compiler errors.

--- libfaac/quantize.c.orig	2017-08-15 13:36:26.000000000 +0000
+++ libfaac/quantize.c
@@ -71,14 +71,14 @@ static void bmask(CoderInfo *coderInfo, 
         target = NOISETONE * pow(avge/avgenrg, powm);
         target += (1.0 - NOISETONE) * 0.45 * pow(maxe/avgenrg, powm);
 
-        target *= 0.9 + (40.0 / (fabs(start + end - MIDF) + 32));
+        target *= 0.9 + (40.0 / (abs(start + end - MIDF) + 32));
     }
     else
     {
         target = NOISETONE * pow(avge/avgenrg, powm);
         target += (1.0 - NOISETONE) * 0.45 * pow(maxe/avgenrg, powm);
 
-        target *= 0.9 + (40.0 / (0.125 * fabs(start + end - (8*MIDF)) + 32));
+        target *= 0.9 + (40.0 / (0.125 * abs(start + end - (8*MIDF)) + 32));
 
         target *= 0.45;
     }
@@ -95,8 +95,8 @@ static void qlevel(CoderInfo *coderInfo,
     int sb, cnt;
     int start, end;
     // 1.5dB step
-    static const double sfstep = 20.0 / 1.5 / log(10);
-    static const double sfstep_1 = 1.0 / sfstep;
+    const double sfstep = 20.0 / 1.5 / log(10);
+    const double sfstep_1 = 1.0 / sfstep;
 
     for (sb = 0; sb < coderInfo->nr_of_sfb; sb++)
     {
