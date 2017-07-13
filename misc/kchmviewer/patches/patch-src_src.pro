$NetBSD: patch-src_src.pro,v 1.2 2017/07/13 13:11:15 wiz Exp $

--- src/src.pro.orig	2016-05-06 18:34:34.000000000 +0000
+++ src/src.pro
@@ -105,3 +105,5 @@ macx-g++: {
 linux-g++-32: {
 	LIBS += -L.
 }
+
+QMAKE_LFLAGS += ${COMPILER_RPATH_FLAG}${X11BASE}/lib ${LDFLAGS}
