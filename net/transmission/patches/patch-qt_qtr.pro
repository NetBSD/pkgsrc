$NetBSD: patch-qt_qtr.pro,v 1.2 2014/04/01 09:48:04 adam Exp $

--- qt/qtr.pro.orig	2014-03-21 11:16:35.000000000 +0000
+++ qt/qtr.pro
@@ -8,12 +8,14 @@ target.path = /bin
 INSTALLS += target
 
 unix: INSTALLS += man
-man.path = /share/man/man1/
+man.path = /man/man1/
 man.files = transmission-qt.1
 
 CONFIG += qt thread debug link_pkgconfig
 QT += network dbus widgets
 PKGCONFIG = fontconfig libcurl openssl libevent
+INCLUDEPATH += $${OPENSSL_CFLAGS}
+LIBS +=  $${OPENSSL_LIBS}
 
 TRANSMISSION_TOP = ..
 
