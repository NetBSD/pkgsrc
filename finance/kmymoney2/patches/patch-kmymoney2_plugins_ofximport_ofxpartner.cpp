$NetBSD: patch-kmymoney2_plugins_ofximport_ofxpartner.cpp,v 1.1 2013/04/30 22:34:30 joerg Exp $

--- kmymoney2/plugins/ofximport/ofxpartner.cpp.orig	2013-04-30 10:59:52.000000000 +0000
+++ kmymoney2/plugins/ofximport/ofxpartner.cpp
@@ -20,6 +20,8 @@
 #include <config.h>
 #endif
 
+#include <unistd.h>
+
 // ----------------------------------------------------------------------------
 // QT Includes
 
