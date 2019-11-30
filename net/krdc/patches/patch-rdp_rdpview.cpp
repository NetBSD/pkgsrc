$NetBSD: patch-rdp_rdpview.cpp,v 1.1 2019/11/30 19:28:45 markd Exp $

pkgsrc renames it xfreerdp2

--- rdp/rdpview.cpp.orig	2019-11-01 21:57:11.000000000 +0000
+++ rdp/rdpview.cpp
@@ -151,7 +151,7 @@ bool RdpView::start()
 
     // Check the version of FreeRDP so we can use pre-1.1 switches if needed
     QProcess *xfreeRDPVersionCheck = new QProcess(this);
-    xfreeRDPVersionCheck->start(QStringLiteral("xfreerdp"), QStringList(QStringLiteral("--version")));
+    xfreeRDPVersionCheck->start(QStringLiteral("xfreerdp2"), QStringList(QStringLiteral("--version")));
     xfreeRDPVersionCheck->waitForFinished();
     QString versionOutput = QString::fromUtf8(xfreeRDPVersionCheck->readAllStandardOutput().constData());
     xfreeRDPVersionCheck->deleteLater();
@@ -367,7 +367,7 @@ bool RdpView::start()
         m_process->start(QStringLiteral("wlfreerdp"), arguments);
     }
     else {
-        m_process->start(QStringLiteral("xfreerdp"), arguments);
+        m_process->start(QStringLiteral("xfreerdp2"), arguments);
     }
 
     return true;
@@ -442,7 +442,7 @@ void RdpView::processError(QProcess::Pro
                 break;
             case KWindowSystem::Platform::X11:
             case KWindowSystem::Platform::Unknown:
-                executable = QStringLiteral("xfreerdp");
+                executable = QStringLiteral("xfreerdp2");
             }
             connectionError(i18n("Could not start \"%1\"; make sure %1 is properly installed.", executable),
                             i18n("RDP Failure"));
