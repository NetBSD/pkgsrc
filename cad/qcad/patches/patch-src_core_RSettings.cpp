$NetBSD: patch-src_core_RSettings.cpp,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix hardcoded paths

--- src/core/RSettings.cpp.orig	2016-08-29 06:49:22.000000000 +0000
+++ src/core/RSettings.cpp
@@ -148,27 +148,7 @@ bool RSettings::isDeployed() {
  * \return Path where all application resources are stored ('scripts', 'patterns', 'ts', 'doc', 'linetypes', ...)
  */
 QString RSettings::getApplicationPath() {
-    QDir ret(QApplication::applicationDirPath());
-
-#ifdef Q_OS_MAC
-    if (ret.dirName() == "MacOS") {
-        ret.cdUp();
-        // deployed (scripts inside app bundle):
-        if (ret.cd("Resources/scripts")) {
-            ret.cdUp();
-        }
-        // development (scripts outside add bundle):
-        else {
-            ret.cdUp();
-            ret.cdUp();
-        }
-    }
-#endif
-
-    if (ret.dirName() == "debug" || ret.dirName() == "release") {
-        ret.cdUp();
-    }
-
+    QDir ret("@PREFIX@/lib/qcad");
     return ret.path();
 }
