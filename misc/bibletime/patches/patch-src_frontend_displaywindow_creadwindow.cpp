$NetBSD: patch-src_frontend_displaywindow_creadwindow.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/72adbba869a14be47967d7e5d877d0e7c49f0375

--- src/frontend/displaywindow/creadwindow.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/displaywindow/creadwindow.cpp
@@ -120,7 +120,7 @@ void CReadWindow::openSearchStrongsDialo
     Q_FOREACH(QString const & strongNumber,
               displayWidget()->getCurrentNodeInfo().split(
                   '|',
-                  QString::SkipEmptyParts))
+                  Qt::SkipEmptyParts))
         searchText.append("strong:").append(strongNumber).append(' ');
     Search::CSearchDialog::openDialog(modules(), searchText, nullptr);
 }
