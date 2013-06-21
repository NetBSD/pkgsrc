$NetBSD: patch-kttsd_plugins_hadifix_hadifixconfigui.ui.h,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/plugins/hadifix/hadifixconfigui.ui.h.orig	2005-09-10 08:13:47.000000000 +0000
+++ kttsd/plugins/hadifix/hadifixconfigui.ui.h
@@ -13,13 +13,13 @@
 // with alpha = 1000/(log(200)-log(50))
 
 int HadifixConfigUI::percentToSlider (int percentValue) {
-   double alpha = 1000 / (log(200) - log(50));
-   return (int)floor (0.5 + alpha * (log(percentValue)-log(50)));
+   double alpha = 1000 / (log((float)200) - log((float)50));
+   return (int)floor (0.5 + alpha * (log((float)percentValue)-log((float)50)));
 }
 
 int HadifixConfigUI::sliderToPercent (int sliderValue) {
-   double alpha = 1000 / (log(200) - log(50));
-   return (int)floor(0.5 + exp (sliderValue/alpha + log(50)));
+   double alpha = 1000 / (log((float)200) - log((float)50));
+   return (int)floor(0.5 + exp (sliderValue/alpha + log((float)50)));
 }
 
 void HadifixConfigUI::volumeBox_valueChanged (int percentValue) {
