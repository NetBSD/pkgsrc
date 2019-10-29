$NetBSD: patch-src_dhcpcd-qt_dhcpcd-wi.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/dhcpcd-wi.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-wi.cpp
@@ -300,7 +300,7 @@ void DhcpcdWi::connectSsid(DHCPCD_WI_SCA
 		if (pwd.isNull() || pwd.isEmpty())
 			err = dhcpcd_wpa_select(wpa, &s);
 		else
-			err = dhcpcd_wpa_configure(wpa, &s, pwd.toAscii());
+			err = dhcpcd_wpa_configure(wpa, &s, pwd.toLatin1());
 	} else
 		err = dhcpcd_wpa_configure(wpa, &s, NULL);
 
