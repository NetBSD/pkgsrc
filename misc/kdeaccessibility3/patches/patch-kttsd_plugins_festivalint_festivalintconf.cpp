$NetBSD: patch-kttsd_plugins_festivalint_festivalintconf.cpp,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/plugins/festivalint/festivalintconf.cpp.orig	2005-10-10 14:52:49.000000000 +0000
+++ kttsd/plugins/festivalint/festivalintconf.cpp
@@ -696,13 +696,13 @@ void FestivalIntConf::slotSelectVoiceCom
 // with alpha = 1000/(log(200)-log(50))
 
 int FestivalIntConf::percentToSlider(int percentValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor (0.5 + alpha * (log(percentValue)-log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor (0.5 + alpha * (log((float)percentValue)-log((float)50)));
 }
 
 int FestivalIntConf::sliderToPercent(int sliderValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor(0.5 + exp (sliderValue/alpha + log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor(0.5 + exp (sliderValue/alpha + log((float)50)));
 }
 
 void FestivalIntConf::volumeBox_valueChanged(int percentValue) {
