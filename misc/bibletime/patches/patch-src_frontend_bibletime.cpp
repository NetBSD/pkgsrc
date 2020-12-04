$NetBSD: patch-src_frontend_bibletime.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/6eb2938ed8b0244fda481c5fbfd7c00588c3d848

--- src/frontend/bibletime.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/bibletime.cpp
@@ -92,7 +92,7 @@ BibleTime::BibleTime(QWidget *parent, Qt
         if (!pm.load(splashImage)) {
             qWarning("Can't load startuplogo! Check your installation.");
         }
-        splash = new QSplashScreen(this, pm);
+        splash = new QSplashScreen(pm);
         splash->setAttribute(Qt::WA_DeleteOnClose);
         splash->finish(this);
         splash->showMessage(splashHtml.arg(tr("Initializing the SWORD engine...")),
