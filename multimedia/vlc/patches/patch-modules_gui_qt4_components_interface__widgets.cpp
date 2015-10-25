$NetBSD: patch-modules_gui_qt4_components_interface__widgets.cpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/components/interface_widgets.cpp.orig	2015-01-22 14:50:00.000000000 +0000
+++ modules/gui/qt4/components/interface_widgets.cpp
@@ -759,13 +759,13 @@ TimeLabel::TimeLabel( intf_thread_t *_p_
     }
     setAlignment( Qt::AlignRight | Qt::AlignVCenter );
 
-    CONNECT( THEMIM->getIM(), positionUpdated( float, int64_t, int ),
-              this, setDisplayPosition( float, int64_t, int ) );
+    CONNECT( THEMIM->getIM(), positionUpdated( float, putime_t, int ),
+              this, setDisplayPosition( float, putime_t, int ) );
 
     setStyleSheet( "QLabel { padding-left: 4px; padding-right: 4px; }" );
 }
 
-void TimeLabel::setDisplayPosition( float pos, int64_t t, int length )
+void TimeLabel::setDisplayPosition( float pos, putime_t t, int length )
 {
     if( pos == -1.f )
     {
