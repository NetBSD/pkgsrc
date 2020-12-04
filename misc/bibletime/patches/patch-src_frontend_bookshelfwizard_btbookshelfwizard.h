$NetBSD: patch-src_frontend_bookshelfwizard_btbookshelfwizard.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/bookshelfwizard/btbookshelfwizard.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/bookshelfwizard/btbookshelfwizard.h
@@ -38,7 +38,7 @@ class BtBookshelfWizard final: public QW
 
 public: /* Methods: */
 
-    BtBookshelfWizard(QWidget * parent = nullptr, Qt::WindowFlags flags = 0);
+    BtBookshelfWizard(QWidget * parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
 
     QStringList selectedSources() const;
     QStringList selectedLanguages() const;
