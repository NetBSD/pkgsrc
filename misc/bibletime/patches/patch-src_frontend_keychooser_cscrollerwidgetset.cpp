$NetBSD: patch-src_frontend_keychooser_cscrollerwidgetset.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/keychooser/cscrollerwidgetset.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/keychooser/cscrollerwidgetset.cpp
@@ -75,7 +75,7 @@ void CScrollerWidgetSet::setToolTips(con
 
 
 void CScrollerWidgetSet::wheelEvent(QWheelEvent * e) {
-    int const delta = e->delta();
+    int const delta = e->angleDelta().y();
     if (delta == 0) {
         e->ignore();
     } else {
