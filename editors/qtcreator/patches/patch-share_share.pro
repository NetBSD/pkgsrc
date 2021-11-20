$NetBSD: patch-share_share.pro,v 1.1 2021/11/20 20:51:14 wiz Exp $

Install desktop files on non-Linux too.

--- share/share.pro.orig	2021-11-03 11:13:10.000000000 +0000
+++ share/share.pro
@@ -3,20 +3,18 @@ SUBDIRS = qtcreator/static.pro
 
 include(../qtcreator.pri)
 
-linux {
-    appdata = $$cat($$PWD/metainfo/org.qt-project.qtcreator.appdata.xml.cmakein, blob)
-    appdata = $$replace(appdata, \\$\\{IDE_VERSION_DISPLAY\\}, $$QTCREATOR_DISPLAY_VERSION)
-    appdata = $$replace(appdata, \\$\\{DATE_ATTRIBUTE\\}, "")
-    write_file($$OUT_PWD/metainfo/org.qt-project.qtcreator.appdata.xml, appdata)
+appdata = $$cat($$PWD/metainfo/org.qt-project.qtcreator.appdata.xml.cmakein, blob)
+appdata = $$replace(appdata, \\$\\{IDE_VERSION_DISPLAY\\}, $$QTCREATOR_DISPLAY_VERSION)
+appdata = $$replace(appdata, \\$\\{DATE_ATTRIBUTE\\}, "")
+write_file($$OUT_PWD/metainfo/org.qt-project.qtcreator.appdata.xml, appdata)
 
-    appstream.files = $$OUT_PWD/metainfo/org.qt-project.qtcreator.appdata.xml
-    appstream.path = $$QTC_PREFIX/share/metainfo/
+appstream.files = $$OUT_PWD/metainfo/org.qt-project.qtcreator.appdata.xml
+appstream.path = $$QTC_PREFIX/share/metainfo/
 
-    desktop.files = share/applications/org.qt-project.qtcreator.desktop
-    desktop.path = $$QTC_PREFIX/share/applications/
+desktop.files = share/applications/org.qt-project.qtcreator.desktop
+desktop.path = $$QTC_PREFIX/share/applications/
 
-    INSTALLS += appstream desktop
-}
+INSTALLS += appstream desktop
 
 defineTest(hasLupdate) {
     cmd = $$eval(QT_TOOL.lupdate.binary)
