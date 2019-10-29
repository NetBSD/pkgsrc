$NetBSD: patch-src_dhcpcd-qt_dhcpcd-qt.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/dhcpcd-qt.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-qt.cpp
@@ -226,9 +226,9 @@ void DhcpcdQt::updateOnline(bool showIf)
 			if (showIf)
 				qDebug() << msg;
 			if (msgs.isEmpty())
-				msgs = QString::fromAscii(msg);
+				msgs = QString::fromLatin1(msg);
 			else
-				msgs += '\n' + QString::fromAscii(msg);
+				msgs += '\n' + QString::fromLatin1(msg);
 			free(msg);
 		} else if (showIf)
 			qDebug() << i->ifname << i->reason;
