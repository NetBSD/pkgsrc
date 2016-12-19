$NetBSD: patch-src_plugins_acoustidimport_fingerprintcalculator.h,v 1.1 2016/12/19 09:20:10 wiz Exp $

Fix build with chromaprint-1.4.x.

--- src/plugins/acoustidimport/fingerprintcalculator.h.orig	2015-09-30 06:40:08.000000000 +0000
+++ src/plugins/acoustidimport/fingerprintcalculator.h
@@ -29,6 +29,7 @@
 
 #include <QObject>
 #include <QString>
+#include <chromaprint.h>
 
 class AbstractFingerprintDecoder;
 
@@ -110,7 +111,7 @@ private slots:
   void finishChromaprint(int duration);
 
 private:
-  void** m_chromaprintCtx;
+  ChromaprintContext* m_chromaprintCtx;
   AbstractFingerprintDecoder* m_decoder;
 };
 
