$NetBSD: patch-kttsd_plugins_epos_eposconf.cpp,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/plugins/epos/eposconf.cpp.orig	2006-01-19 16:17:11.000000000 +0000
+++ kttsd/plugins/epos/eposconf.cpp
@@ -293,13 +293,13 @@ void EposConf::slotSynthStopped()
 // with alpha = 1000/(log(200)-log(50))
 
 int EposConf::percentToSlider(int percentValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor (0.5 + alpha * (log(percentValue)-log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor (0.5 + alpha * (log((float)percentValue)-log((float)50)));
 }
 
 int EposConf::sliderToPercent(int sliderValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor(0.5 + exp (sliderValue/alpha + log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor(0.5 + exp (sliderValue/alpha + log((float)50)));
 }
 
 void EposConf::timeBox_valueChanged(int percentValue) {
