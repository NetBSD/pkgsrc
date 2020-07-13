$NetBSD: patch-qt_qtr.pro,v 1.7 2020/07/13 13:01:01 wiz Exp $

1. Fix man page installation path.
2. add openssl cflags/ldflags (still needed?)

--- qt/qtr.pro.orig	2020-05-22 11:04:23.470805450 +0000
+++ qt/qtr.pro
@@ -8,7 +8,8 @@ target.path = /bin
 INSTALLS += target
 
 unix: INSTALLS += man
-man.path = /share/man/man1/
+man.path = /man/man1/
+
 man.files = transmission-qt.1
 
 CONFIG += qt thread link_pkgconfig c++1z warn_on
@@ -29,12 +30,14 @@ include(config.pri)
 
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
