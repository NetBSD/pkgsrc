$NetBSD: patch-src_desktop_widgets_popupmessage.h,v 1.1 2021/07/20 10:54:18 nia Exp $

Fix building with latest Qt.

--- src/desktop/widgets/popupmessage.h.orig	2020-02-16 16:35:42.000000000 +0000
+++ src/desktop/widgets/popupmessage.h
@@ -20,6 +20,7 @@
 #define POPUPMESSAGE_H
 
 #include <QWidget>
+#include <QPainterPath>
 
 class QTextDocument;
 class QTimer;
