$NetBSD: patch-src_gui_main.cpp,v 1.2 2015/03/29 15:28:43 rodent Exp $

Fix buildling on Mac OS X.

--- src/gui/main.cpp.orig	2012-03-23 06:10:54.000000000 +0000
+++ src/gui/main.cpp
@@ -72,9 +72,6 @@
 #include "fwbuilder/Constants.h"
 
 
-#if defined(Q_WS_MAC)
-extern void connectOdocHandler();
-#endif
 
 #ifndef INIT2
 #define INIT2
@@ -257,9 +254,6 @@ int main( int argc, char *argv[] )
     // connecting to right slot
     app->connect(app, SIGNAL(lastWindowClosed()), app, SLOT(quit()));
 
-#if defined(Q_WS_MAC)
-    connectOdocHandler();
-#endif
 
     // setup single shot timer to call startupLoad()
     QTimer::singleShot(500, mw, SLOT(startupLoad()));
