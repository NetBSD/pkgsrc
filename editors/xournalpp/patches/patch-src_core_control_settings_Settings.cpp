$NetBSD: patch-src_core_control_settings_Settings.cpp,v 1.1 2023/08/06 11:59:42 yhardy Exp $

On NetBSD, absolute coordinate changes are reported as an X value followed by a Y value,
which (when moving quickly) leads to a "stepping" effect. Make the stroke stabilizer
default to "on" in this case.

--- src/core/control/settings/Settings.cpp.orig	2021-07-18 21:18:39.000000000 +0000
+++ src/core/control/settings/Settings.cpp
@@ -183,8 +183,13 @@ void Settings::loadDefault() {
     /**
      * Stabilizer related settings
      */
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+    this->stabilizerAveragingMethod = StrokeStabilizer::AveragingMethod::VELOCITY_GAUSSIAN;
+    this->stabilizerPreprocessor = StrokeStabilizer::Preprocessor::NONE;
+#else
     this->stabilizerAveragingMethod = StrokeStabilizer::AveragingMethod::NONE;
     this->stabilizerPreprocessor = StrokeStabilizer::Preprocessor::NONE;
+#endif
     this->stabilizerBuffersize = 20;
     this->stabilizerSigma = 0.5;
     this->stabilizerDeadzoneRadius = 1.3;
