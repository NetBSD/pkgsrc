$NetBSD: patch-src_frontend_keychooser_versekeychooser_btdropdownchooserbutton.cpp,v 1.1 2020/12/04 12:17:59 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/keychooser/versekeychooser/btdropdownchooserbutton.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/keychooser/versekeychooser/btdropdownchooserbutton.cpp
@@ -49,7 +49,7 @@ void BtDropdownChooserButton::mousePress
 }
 
 void BtDropdownChooserButton::wheelEvent(QWheelEvent * e) {
-    int const delta = e->delta();
+    int const delta = e->angleDelta().y();
     if (delta == 0) {
         e->ignore();
     } else {
