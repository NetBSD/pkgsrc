$NetBSD: patch-src_utp_delaywindow.h,v 1.1 2014/11/17 19:59:40 markd Exp $

--- src/utp/delaywindow.h.orig	2013-01-14 17:09:10.000000000 +0000
+++ src/utp/delaywindow.h
@@ -22,7 +22,9 @@
 #ifndef UTP_DELAYWINDOW_H
 #define UTP_DELAYWINDOW_H
 
+#ifndef Q_MOC_RUN
 #include <boost/circular_buffer.hpp>
+#endif
 #include <utp/utpprotocol.h>
 
 namespace utp
