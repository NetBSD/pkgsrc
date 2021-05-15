$NetBSD: patch-qtcreator.pro,v 1.1 2021/05/15 11:42:24 nia Exp $

Install desktop files on non-Linux too.

--- qtcreator.pro.orig	2020-10-01 00:17:08.000000000 +0000
+++ qtcreator.pro
@@ -97,15 +97,13 @@ else: PLATFORM = "unknown"
 BASENAME = $$(INSTALL_BASENAME)
 isEmpty(BASENAME): BASENAME = qt-creator-$${PLATFORM}$(INSTALL_EDITION)-$${QTCREATOR_VERSION}$(INSTALL_POSTFIX)
 
-linux {
-    appstream.files = share/metainfo/org.qt-project.qtcreator.appdata.xml
-    appstream.path = $$QTC_PREFIX/share/metainfo/
+appstream.files = share/metainfo/org.qt-project.qtcreator.appdata.xml
+appstream.path = $$QTC_PREFIX/share/metainfo/
 
-    desktop.files = share/applications/org.qt-project.qtcreator.desktop
-    desktop.path = $$QTC_PREFIX/share/applications/
+desktop.files = share/applications/org.qt-project.qtcreator.desktop
+desktop.path = $$QTC_PREFIX/share/applications/
 
-    INSTALLS += appstream desktop
-}
+INSTALLS += appstream desktop
 
 macx {
     APPBUNDLE = "$$OUT_PWD/bin/$${IDE_APP_TARGET}.app"
