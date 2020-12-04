$NetBSD: patch-src_frontend_btbookshelfdockwidget.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/btbookshelfdockwidget.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/btbookshelfdockwidget.h
@@ -29,7 +29,7 @@ class QStackedWidget;
 class BtBookshelfDockWidget: public QDockWidget {
         Q_OBJECT
     public:
-        BtBookshelfDockWidget(QWidget *parent = nullptr, Qt::WindowFlags f = nullptr);
+        BtBookshelfDockWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
 
         static inline BtBookshelfDockWidget *getInstance() { return m_instance; }
 
