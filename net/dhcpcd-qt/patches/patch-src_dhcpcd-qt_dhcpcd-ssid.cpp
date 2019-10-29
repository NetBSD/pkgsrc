$NetBSD: patch-src_dhcpcd-qt_dhcpcd-ssid.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Fix compiler warning.

--- src/dhcpcd-qt/dhcpcd-ssid.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-ssid.cpp
@@ -74,8 +74,6 @@ DhcpcdSsid::DhcpcdSsid(DhcpcdWi *parent,
 
 QString DhcpcdSsid::getPsk(bool *ok)
 {
-	int r;
-
 	exec();
 	if (result() == QDialog::Rejected) {
 		if (ok)
