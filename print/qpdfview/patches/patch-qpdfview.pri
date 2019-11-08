$NetBSD: patch-qpdfview.pri,v 1.5 2019/11/08 13:38:48 nia Exp $

* Set install places

--- qpdfview.pri.orig	2019-07-24 19:18:33.000000000 +0000
+++ qpdfview.pri
@@ -1,12 +1,12 @@
 isEmpty(APPLICATION_VERSION):APPLICATION_VERSION = 0.4.18
 
-isEmpty(TARGET_INSTALL_PATH):TARGET_INSTALL_PATH = /usr/bin
-isEmpty(PLUGIN_INSTALL_PATH):PLUGIN_INSTALL_PATH = /usr/lib/qpdfview
-isEmpty(DATA_INSTALL_PATH):DATA_INSTALL_PATH = /usr/share/qpdfview
-isEmpty(MANUAL_INSTALL_PATH):MANUAL_INSTALL_PATH = /usr/share/man/man1
-isEmpty(ICON_INSTALL_PATH):ICON_INSTALL_PATH = /usr/share/icons/hicolor/scalable/apps
-isEmpty(LAUNCHER_INSTALL_PATH):LAUNCHER_INSTALL_PATH = /usr/share/applications
-isEmpty(APPDATA_INSTALL_PATH):APPDATA_INSTALL_PATH = /usr/share/appdata
+isEmpty(TARGET_INSTALL_PATH):TARGET_INSTALL_PATH = $$(PREFIX)/bin
+isEmpty(PLUGIN_INSTALL_PATH):PLUGIN_INSTALL_PATH = $$(PREFIX)/lib/qpdfview
+isEmpty(DATA_INSTALL_PATH):DATA_INSTALL_PATH = $$(PREFIX)/share/qpdfview
+isEmpty(MANUAL_INSTALL_PATH):MANUAL_INSTALL_PATH = $$(PREFIX)/$$(PKGMANDIR)/man1
+isEmpty(ICON_INSTALL_PATH):ICON_INSTALL_PATH = $$(PREFIX)/share/icons/hicolor
+isEmpty(LAUNCHER_INSTALL_PATH):LAUNCHER_INSTALL_PATH = $$(PREFIX)/share/applications
+isEmpty(APPDATA_INSTALL_PATH):APPDATA_INSTALL_PATH = $$(PREFIX)/share/appdata
 
 win32:include(qpdfview_win32.pri)
 os2:include(qpdfview_os2.pri)
