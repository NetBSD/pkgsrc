$NetBSD: patch-qt_qtr.pro,v 1.3 2014/05/30 13:46:30 wiz Exp $

--- qt/qtr.pro.orig	2014-05-18 20:52:17.000000000 +0000
+++ qt/qtr.pro
@@ -8,7 +8,8 @@ target.path = /bin
 INSTALLS += target
 
 unix: INSTALLS += man
-man.path = /share/man/man1/
+man.path = /man/man1/
+
 man.files = transmission-qt.1
 
 CONFIG += qt thread debug link_pkgconfig c++11 warn_on
@@ -25,11 +26,13 @@ include(config.pri) 
 
 INCLUDEPATH = $${EVENT_TOP}/include $${INCLUDEPATH}
 INCLUDEPATH += $${TRANSMISSION_TOP}
+INCLUDEPATH += $${OPENSSL_CFLAGS}
 LIBS += $${TRANSMISSION_TOP}/libtransmission/libtransmission.a
 LIBS += $${LIBUTP_LIBS}
 LIBS += $${TRANSMISSION_TOP}/third-party/dht/libdht.a
 LIBS += $${LIBUPNP_LIBS}
 LIBS += $${LIBNATPMP_LIBS}
+LIBS += $${OPENSSL_LIBS}
 unix: LIBS += -L$${EVENT_TOP}/lib -lz -lrt
 win32:DEFINES += QT_DBUS
 win32:LIBS += -levent-2.0 -lws2_32 -lintl
