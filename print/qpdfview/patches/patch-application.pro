$NetBSD: patch-application.pro,v 1.3 2026/08/07 16:22:10 ryoon Exp $

* install png icons (makes the icon visible in xfce)

The reason .files and .path are not set within the for loop using 
$${size} is that when done messages like:

WARNING: icon16.path is not defined: install target not created
appear when the .pro file is processed and the icons won't be installed.

--- application.pro.orig	2023-01-28 10:40:47.229000000 +0000
+++ application.pro
@@ -278,7 +278,14 @@ system("sed -e \"s:DATA_INSTALL_PATH:$${DATA_INSTALL_P
 
 system("sed -e \"s:DATA_INSTALL_PATH:$${DATA_INSTALL_PATH}:\" -e \"s:MIME_TYPES:$$join(MIME_TYPES,";","",";"):\" $${DESKTOP_FILE}.in > $${DESKTOP_FILE}")
 
+iconsizes = 16 22 24 32 36 48 64 72 96 128 160 192 256
 
+system(mkdir tmp)
+for(size, iconsizes) {
+    system(mkdir tmp/$${size})
+    system(rsvg-convert -w $${size} -h $${size} -f png -o tmp/$${size}/qpdfview.png icons/qpdfview.svg)
+}
+
 target.path = $${TARGET_INSTALL_PATH}
 
 data.files = translations/*.qm help/help*.html
@@ -288,8 +295,47 @@ icon.files = icons/qpdfview.svg
 manual.path = $${MANUAL_INSTALL_PATH}
 
 icon.files = icons/qpdfview.svg
-icon.path = $${ICON_INSTALL_PATH}
+icon.path = $${ICON_INSTALL_PATH}/scalable/apps
 
+icon16.files = tmp/16/qpdfview.png
+icon16.path = $${ICON_INSTALL_PATH}/16x16/apps
+
+icon22.files = tmp/22/qpdfview.png
+icon22.path = $${ICON_INSTALL_PATH}/22x22/apps
+
+icon24.files = tmp/24/qpdfview.png
+icon24.path = $${ICON_INSTALL_PATH}/24x24/apps
+
+icon32.files = tmp/32/qpdfview.png
+icon32.path = $${ICON_INSTALL_PATH}/32x32/apps
+
+icon36.files = tmp/36/qpdfview.png
+icon36.path = $${ICON_INSTALL_PATH}/36x36/apps
+
+icon48.files = tmp/48/qpdfview.png
+icon48.path = $${ICON_INSTALL_PATH}/48x48/apps
+
+icon64.files = tmp/64/qpdfview.png
+icon64.path = $${ICON_INSTALL_PATH}/64x64/apps
+
+icon72.files = tmp/72/qpdfview.png
+icon72.path = $${ICON_INSTALL_PATH}/72x72/apps
+
+icon96.files = tmp/96/qpdfview.png
+icon96.path = $${ICON_INSTALL_PATH}/96x96/apps
+
+icon128.files = tmp/128/qpdfview.png
+icon128.path = $${ICON_INSTALL_PATH}/128x128/apps
+
+icon160.files = tmp/160/qpdfview.png
+icon160.path = $${ICON_INSTALL_PATH}/160x160/apps
+
+icon192.files = tmp/192/qpdfview.png
+icon192.path = $${ICON_INSTALL_PATH}/192x192/apps
+
+icon256.files = tmp/256/qpdfview.png
+icon256.path = $${ICON_INSTALL_PATH}/256x256/apps
+
 launcher.files = $${DESKTOP_FILE}
 launcher.path = $${LAUNCHER_INSTALL_PATH}
 
@@ -297,6 +343,8 @@ INSTALLS += target data manual icon launcher appdata
 appdata.path = $${APPDATA_INSTALL_PATH}
 
 INSTALLS += target data manual icon launcher appdata
+INSTALLS += icon16 icon22 icon24 icon32 icon36 icon48 icon64 icon72
+INSTALLS += icon96 icon128 icon160 icon192 icon256
 
 INCLUDEPATH += icons
 win32:RC_FILE = icons/qpdfview_win32.rc
