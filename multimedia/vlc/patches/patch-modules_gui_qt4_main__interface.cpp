$NetBSD: patch-modules_gui_qt4_main__interface.cpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/main_interface.cpp.orig	2015-02-26 20:21:25.000000000 +0000
+++ modules/gui/qt4/main_interface.cpp
@@ -399,13 +399,13 @@ void MainInterface::createResumePanel( Q
 
     CONNECT( resumeTimer, timeout(), this, hideResumePanel() );
     CONNECT( cancel, clicked(), this, hideResumePanel() );
-    CONNECT( THEMIM->getIM(), resumePlayback(int64_t), this, showResumePanel(int64_t) );
+    CONNECT( THEMIM->getIM(), resumePlayback(putime_t), this, showResumePanel(putime_t) );
     BUTTONACT( ok, resumePlayback() );
 
     w->layout()->addWidget( resumePanel );
 }
 
-void MainInterface::showResumePanel( int64_t _time ) {
+void MainInterface::showResumePanel( putime_t _time ) {
     int setting = var_InheritInteger( p_intf, "qt-continue" );
 
     if( setting == 0 )
