$NetBSD: patch-src_core_RSettings.cpp,v 1.4 2025/08/19 12:52:17 plunky Exp $

fix hardcoded paths

--- src/core/RSettings.cpp.orig	2025-06-10 07:10:41.000000000 +0000
+++ src/core/RSettings.cpp
@@ -376,6 +376,7 @@ bool RSettings::isDeployed() {
  * \return Path where all application resources are stored ('scripts', 'patterns', 'ts', 'doc', 'linetypes', ...)
  */
 QString RSettings::getApplicationPath() {
+#if 0
     QDir ret(QApplication::applicationDirPath());
 
 #ifdef Q_OS_MAC
@@ -397,6 +398,8 @@ QString RSettings::getApplicationPath() 
         ret.cdUp();
     }
 
+#endif
+    QDir ret("@PREFIX@/lib/qcad");
     return ret.path();
 }
 
