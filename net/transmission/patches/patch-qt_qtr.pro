$NetBSD: patch-qt_qtr.pro,v 1.5 2017/07/13 13:38:59 wiz Exp $

--- qt/qtr.pro.orig	2015-12-29 00:47:32.464150631 +0000
+++ qt/qtr.pro
@@ -8,7 +8,8 @@ target.path = /bin
 INSTALLS += target
 
 unix: INSTALLS += man
-man.path = /share/man/man1/
+man.path = /man/man1/
+
 man.files = transmission-qt.1
 
 CONFIG += qt thread debug link_pkgconfig c++11 warn_on
@@ -28,12 +29,14 @@ include(config.pri)
 
 INCLUDEPATH = $${EVENT_TOP}/include $${INCLUDEPATH}
 INCLUDEPATH += $${TRANSMISSION_TOP}
+INCLUDEPATH += $${OPENSSL_CFLAGS}
 LIBS += $${TRANSMISSION_TOP}/libtransmission/libtransmission.a
 LIBS += $${LIBUTP_LIBS}
 LIBS += $${DHT_LIBS}
 LIBS += $${LIBB64_LIBS}
 LIBS += $${LIBUPNP_LIBS}
 LIBS += $${LIBNATPMP_LIBS}
+LIBS += $${OPENSSL_LIBS} ${LDFLAGS}
 unix: LIBS += -L$${EVENT_TOP}/lib -lz -lrt
 win32:LIBS += -levent-2.0 -lws2_32 -lintl
 win32:LIBS += -lidn -liconv -lwldap32 -liphlpapi
