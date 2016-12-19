$NetBSD: patch-src_plugins_acoustidimport_fingerprintcalculator.cpp,v 1.1 2016/12/19 09:20:10 wiz Exp $

Fix build with chromaprint-1.4.x.

--- src/plugins/acoustidimport/fingerprintcalculator.cpp.orig	2015-09-30 06:40:08.000000000 +0000
+++ src/plugins/acoustidimport/fingerprintcalculator.cpp
@@ -26,7 +26,6 @@
 
 #define __STDC_CONSTANT_MACROS
 #include "fingerprintcalculator.h"
-#include <chromaprint.h>
 #include "config.h"
 #include "abstractfingerprintdecoder.h"
 
@@ -94,7 +93,7 @@ void FingerprintCalculator::startChromap
  */
 void FingerprintCalculator::feedChromaprint(QByteArray data)
 {
-  if (!::chromaprint_feed(m_chromaprintCtx, data.data(), data.size() / 2)) {
+  if (!::chromaprint_feed(m_chromaprintCtx, (int16_t*)data.data(), data.size() / 2)) {
     m_decoder->stop();
     emit finished(QString(), 0, FingerprintCalculationFailed);
   }
