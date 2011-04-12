$NetBSD: patch-src_gui_main.cpp,v 1.1 2011/04/12 13:44:03 adam Exp $

Fix buildling on Mac OS X.

--- src/gui/main.cpp.orig	2011-04-11 20:07:30.000000000 +0000
+++ src/gui/main.cpp
@@ -71,9 +71,6 @@
 #include "fwbuilder/Resources.h"
 #include "fwbuilder/FWException.h"
 
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
