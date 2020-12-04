$NetBSD: patch-src_frontend_settingsdialogs_btconfigdialog.h,v 1.1 2020/12/04 12:17:59 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/settingsdialogs/btconfigdialog.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/settingsdialogs/btconfigdialog.h
@@ -72,7 +72,7 @@ public: /* Types: */
 public: /* Methods: */
 
     BtConfigDialog(QWidget * const parent = nullptr,
-                   Qt::WindowFlags const flags = 0);
+                   Qt::WindowFlags const flags = Qt::WindowFlags());
 
     /** Adds a BtConfigPage to the paged widget stack. The new page will be the current page.*/
     void addPage(Page * const pageWidget);
