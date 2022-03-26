$NetBSD: patch-src_plugins_sine.cpp,v 1.1 2022/03/26 22:06:11 tnn Exp $

cast pow(3) exponent to canonical type

--- src/plugins/sine.cpp.orig	2021-09-10 08:50:46.000000000 +0000
+++ src/plugins/sine.cpp
@@ -62,7 +62,7 @@ initialise_sine_table() {
 	g_pfSineTable[lIndex] = LADSPA_Data(sin(dShift * lIndex));
   }
   if (g_fPhaseStepBase == 0) {
-    g_fPhaseStepBase = (LADSPA_Data)pow(2, sizeof(unsigned long) * 8);
+    g_fPhaseStepBase = (LADSPA_Data)pow(2, (double)sizeof(unsigned long) * 8);
   }
 }
 
