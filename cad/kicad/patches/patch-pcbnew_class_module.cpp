$NetBSD: patch-pcbnew_class_module.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_module.cpp.orig	2014-02-15 15:41:28.000000000 +0100
+++ pcbnew/class_module.cpp	2014-02-15 15:41:37.000000000 +0100
@@ -458,7 +458,7 @@
     aList.push_back( MSG_PANEL_ITEM( _( "Last Change" ), msg, BROWN ) );
 
     // display time stamp in schematic
-    msg.Printf( wxT( "%8.8lX" ), m_TimeStamp );
+    msg.Printf( wxT( "%8.8lX" ), (u_long)m_TimeStamp );
     aList.push_back( MSG_PANEL_ITEM( _( "Netlist path" ), m_Path, BROWN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Layer" ), board->GetLayerName( m_Layer ), RED ) );
 
