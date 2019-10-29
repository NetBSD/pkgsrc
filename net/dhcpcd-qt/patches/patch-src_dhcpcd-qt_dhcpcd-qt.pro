$NetBSD: patch-src_dhcpcd-qt_dhcpcd-qt.pro,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/dhcpcd-qt.pro.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-qt.pro
@@ -1,5 +1,6 @@
 CONFIG+=		qt gui c++11 debug
 QMAKE_CXXFLAGS+=	-std=c++11 -O2
+QT+=			core gui widgets
 
 HEADERS=		dhcpcd-qt.h dhcpcd-about.h dhcpcd-preferences.h \
 			dhcpcd-wi.h dhcpcd-ifmenu.h \
