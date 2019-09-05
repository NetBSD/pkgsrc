$NetBSD: patch-versiondialog.cpp,v 1.1 2019/09/05 08:07:25 nros Exp $
* set right version url
--- versiondialog.cpp.orig	2019-09-03 18:03:49.000000000 +0000
+++ versiondialog.cpp
@@ -42,7 +42,7 @@ void VersionDialog::launchChecker()
 {
 ui.pushButtonCheck->setEnabled(false);
 timer.start(10000);
-reply = manager.get (  QNetworkRequest(QUrl("http://www.xm1math.net/texmaker/version.txt"))  );
+reply = manager.get (  QNetworkRequest(QUrl("https://www.xm1math.net/texmaker/version.txt"))  );
 QObject::connect (reply, SIGNAL (finished()),this, SLOT(showResultChecker()));
 }
 
