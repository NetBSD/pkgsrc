$NetBSD: patch-rdp_rdpviewfactory.cpp,v 1.1 2019/11/30 19:28:45 markd Exp $

pkgsrc renames it xfreerdp2

--- rdp/rdpviewfactory.cpp.orig	2019-11-01 21:57:11.000000000 +0000
+++ rdp/rdpviewfactory.cpp
@@ -83,7 +83,7 @@ QString RdpViewFactory::connectToolTipTe
 
 void RdpViewFactory::checkFreerdpAvailability()
 {
-    if (QStandardPaths::findExecutable(QStringLiteral("xfreerdp")).isEmpty()) {
+    if (QStandardPaths::findExecutable(QStringLiteral("xfreerdp2")).isEmpty()) {
         m_connectToolTipString += QLatin1Char('\n') + i18n("The application \"xfreerdp\" cannot be found on your system; make sure it is properly installed "
                                               "if you need RDP support.");
     }
