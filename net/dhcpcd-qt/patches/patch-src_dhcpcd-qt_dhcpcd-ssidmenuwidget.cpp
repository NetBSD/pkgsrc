$NetBSD: patch-src_dhcpcd-qt_dhcpcd-ssidmenuwidget.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/dhcpcd-ssidmenuwidget.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-ssidmenuwidget.cpp
@@ -115,7 +115,8 @@ void DhcpcdSsidMenuWidget::setScan(DHCPC
 		selicon->setPixmap(picon);
 		ssid->setStyleSheet("font:bold;");
 	} else {
-		selicon->setPixmap(NULL);
+		QPixmap		emptyPixmap;
+		selicon->setPixmap(emptyPixmap);
 		ssid->setStyleSheet(NULL);
 	}
 	ssid->setText(scan->ssid);
