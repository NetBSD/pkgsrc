$NetBSD: patch-support_examples_transactionlistener_transactionlistener.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- support/examples/transactionlistener/transactionlistener.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ support/examples/transactionlistener/transactionlistener.pro
@@ -6,4 +6,7 @@ TEMPLATE    = lib
 HEADERS     = TransactionListenerPlugin.h
 SOURCES     = TransactionListenerPlugin.cpp
 DESTDIR     = ../../../plugins
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}gui
+INSTALLS += target
+target.path = $${PREFIX}/lib/$${RLIBNAME}/plugins
+LIBS += -L../../../src/core -l$${RLIBNAME}core \
+	-L../../../src/gui -l$${RLIBNAME}gui
