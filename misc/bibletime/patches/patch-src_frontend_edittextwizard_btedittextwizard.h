$NetBSD: patch-src_frontend_edittextwizard_btedittextwizard.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/edittextwizard/btedittextwizard.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/edittextwizard/btedittextwizard.h
@@ -26,7 +26,7 @@ class BtEditTextWizard final: public QWi
 
 public: /* Methods: */
 
-    BtEditTextWizard(QWidget * parent = nullptr, Qt::WindowFlags flags = 0);
+    BtEditTextWizard(QWidget * parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
 
     bool htmlMode() const;
     void setFont(const QFont& font);
