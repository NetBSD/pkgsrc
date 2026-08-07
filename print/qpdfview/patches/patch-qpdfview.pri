$NetBSD: patch-qpdfview.pri,v 1.6 2026/08/07 16:22:10 ryoon Exp $

* Set install places

--- qpdfview.pri.orig	2023-01-28 10:40:47.229000000 +0000
+++ qpdfview.pri
@@ -1,12 +1,12 @@ isEmpty(APPLICATION_VERSION):APPLICATION_VERSION = 0.5
 isEmpty(APPLICATION_VERSION):APPLICATION_VERSION = 0.5.0
 
-isEmpty(TARGET_INSTALL_PATH):TARGET_INSTALL_PATH = /usr/bin
-isEmpty(PLUGIN_INSTALL_PATH):PLUGIN_INSTALL_PATH = /usr/lib/qpdfview
-isEmpty(DATA_INSTALL_PATH):DATA_INSTALL_PATH = /usr/share/qpdfview
-isEmpty(MANUAL_INSTALL_PATH):MANUAL_INSTALL_PATH = /usr/share/man/man1
-isEmpty(ICON_INSTALL_PATH):ICON_INSTALL_PATH = /usr/share/icons/hicolor/scalable/apps
-isEmpty(LAUNCHER_INSTALL_PATH):LAUNCHER_INSTALL_PATH = /usr/share/applications
-isEmpty(APPDATA_INSTALL_PATH):APPDATA_INSTALL_PATH = /usr/share/metainfo
+isEmpty(TARGET_INSTALL_PATH):TARGET_INSTALL_PATH = $$(PREFIX)/bin
+isEmpty(PLUGIN_INSTALL_PATH):PLUGIN_INSTALL_PATH = $$(PREFIX)/lib/qpdfview
+isEmpty(DATA_INSTALL_PATH):DATA_INSTALL_PATH = $$(PREFIX)/share/qpdfview
+isEmpty(MANUAL_INSTALL_PATH):MANUAL_INSTALL_PATH = $$(PREFIX)/$$(PKGMANDIR)/man1
+isEmpty(ICON_INSTALL_PATH):ICON_INSTALL_PATH = $$(PREFIX)/share/icons/hicolor/scalable/apps
+isEmpty(LAUNCHER_INSTALL_PATH):LAUNCHER_INSTALL_PATH = $$(PREFIX)/share/applications
+isEmpty(APPDATA_INSTALL_PATH):APPDATA_INSTALL_PATH = $$(PREFIX)/share/metainfo
 isEmpty(APP_DIR_DATA_PATH):APP_DIR_DATA_PATH = data
 
 win32:include(qpdfview_win32.pri)
