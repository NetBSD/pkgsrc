$NetBSD: patch-minitube.pro,v 1.1 2020/08/12 11:39:55 ryoon Exp $

From upstream:
https://github.com/flaviotordini/minitube/commit/2cd1d48d5d4505dd785adee7963ac01e5850d8ce

--- minitube.pro.orig	2020-08-07 09:22:48.000000000 +0000
+++ minitube.pro
@@ -43,6 +43,8 @@ include(lib/media/media.pri)
 include(src/qtsingleapplication/qtsingleapplication.pri)
 include(src/invidious/invidious.pri)
 
+INCLUDEPATH += $$PWD/src
+
 HEADERS += src/video.h \
     src/messagebar.h \
     src/spacer.h \
