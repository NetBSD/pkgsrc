$NetBSD: patch-src_gui_entry_EditEntryWidget.cpp,v 1.1 2018/06/23 08:20:36 wiz Exp $

Qt-5.11 fix, based on
https://github.com/keepassxreboot/keepassxc/commit/3bbc6ac0e6298d27bfe0c41999460cafda8edf18

--- src/gui/entry/EditEntryWidget.cpp.orig	2018-05-09 17:25:19.000000000 +0000
+++ src/gui/entry/EditEntryWidget.cpp
@@ -29,6 +29,7 @@
 #include <QMenu>
 #include <QSortFilterProxyModel>
 #include <QTemporaryFile>
+#include <QButtonGroup>
 #include <QMimeData>
 #include <QEvent>
 #include <QColorDialog>
