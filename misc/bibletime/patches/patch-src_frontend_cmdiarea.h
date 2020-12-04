$NetBSD: patch-src_frontend_cmdiarea.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/cmdiarea.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/cmdiarea.h
@@ -55,7 +55,7 @@ class CMDIArea: public QMdiArea {
           Reimplementation of QMdiArea::addSubWindow().
         */
         QMdiSubWindow * addSubWindow(QWidget * widget,
-                                     Qt::WindowFlags windowFlags = nullptr);
+                                     Qt::WindowFlags windowFlags = Qt::WindowFlags());
 
         /**
           Returns the BibleTime main window
