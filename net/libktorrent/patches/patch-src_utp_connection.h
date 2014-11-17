$NetBSD: patch-src_utp_connection.h,v 1.1 2014/11/17 19:59:40 markd Exp $

--- src/utp/connection.h.orig	2014-11-17 18:38:46.000000000 +0000
+++ src/utp/connection.h
@@ -32,7 +32,9 @@
 #include <util/circularbuffer.h>
 #include <util/timer.h>
 #include <utp/remotewindow.h>
+#ifndef Q_MOC_RUN
 #include <boost/concept_check.hpp>
+#endif
 
 
 
