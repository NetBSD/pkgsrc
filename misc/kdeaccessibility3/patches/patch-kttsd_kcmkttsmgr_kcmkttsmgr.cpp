$NetBSD: patch-kttsd_kcmkttsmgr_kcmkttsmgr.cpp,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/kcmkttsmgr/kcmkttsmgr.cpp.orig	2006-03-17 10:07:37.000000000 +0000
+++ kttsd/kcmkttsmgr/kcmkttsmgr.cpp
@@ -2139,13 +2139,13 @@ void KCMKttsMgr::keepAudioCheckBox_toggl
 // with alpha = 1000/(log(200)-log(50))
 
 int KCMKttsMgr::percentToSlider(int percentValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor (0.5 + alpha * (log(percentValue)-log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor (0.5 + alpha * (log((float)percentValue)-log((float)50)));
 }
 
 int KCMKttsMgr::sliderToPercent(int sliderValue) {
-    double alpha = 1000 / (log(200) - log(50));
-    return (int)floor(0.5 + exp (sliderValue/alpha + log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    return (int)floor(0.5 + exp (sliderValue/alpha + log((float)50)));
 }
 
 void KCMKttsMgr::timeBox_valueChanged(int percentValue) {
