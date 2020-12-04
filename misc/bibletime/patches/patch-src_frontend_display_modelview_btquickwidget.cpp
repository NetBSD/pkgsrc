$NetBSD: patch-src_frontend_display_modelview_btquickwidget.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* don't install DisplayView.qml in bin
 taken from upstream https://github.com/bibletime/bibletime/commit/7700e93a345c202cd45cd4e72b77feb64fe33b80

--- src/frontend/display/modelview/btquickwidget.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/display/modelview/btquickwidget.cpp
@@ -36,7 +36,7 @@ BtQuickWidget::BtQuickWidget(BtQmlScroll
     setAcceptDrops(true);
 
     namespace DU = util::directory;
-    QString qmlFile = QCoreApplication::applicationDirPath() + "/" + "DisplayView.qml";
+    QString qmlFile = QCoreApplication::applicationDirPath() + "/../share/bibletime/qml/" + "DisplayView.qml";
     setSource(QUrl::fromLocalFile(qmlFile));
     setupScrollTimer();
 }
