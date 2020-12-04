$NetBSD: patch-src_frontend_keychooser_ckeychooserwidget.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/keychooser/ckeychooserwidget.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/keychooser/ckeychooserwidget.cpp
@@ -67,17 +67,17 @@ bool CKCComboBox::eventFilter(QObject * 
             return false;
 
         if (f->reason() == Qt::ActiveWindowFocusReason) {
-            emit activated(currentText());
+            emit textActivated(currentText());
             return false;
         }
 
         if (f->reason() == Qt::MouseFocusReason) {
-            emit activated(currentText());
+            emit textActivated(currentText());
             return false;
         }
 
         if (o == this) {
-            emit activated(currentText());
+            emit textActivated(currentText());
             return false;
         }
     }
