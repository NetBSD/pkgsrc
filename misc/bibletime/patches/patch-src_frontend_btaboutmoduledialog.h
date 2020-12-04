$NetBSD: patch-src_frontend_btaboutmoduledialog.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/btaboutmoduledialog.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/btaboutmoduledialog.h
@@ -31,7 +31,7 @@ class BTAboutModuleDialog: public QDialo
 
         BTAboutModuleDialog(const CSwordModuleInfo *moduleInfo,
                             QWidget *parent = nullptr,
-                            Qt::WindowFlags flags = nullptr);
+                            Qt::WindowFlags flags = Qt::WindowFlags());
 
     protected: /* Methods: */
 
