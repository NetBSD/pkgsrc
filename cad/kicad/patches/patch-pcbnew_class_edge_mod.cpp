$NetBSD: patch-pcbnew_class_edge_mod.cpp,v 1.4 2019/06/08 11:04:28 rillig Exp $

64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_edge_mod.cpp.orig	2015-12-11 18:00:51.000000000 +0100
+++ pcbnew/class_edge_mod.cpp	2015-12-11 18:01:09.000000000 +0100
@@ -259,7 +259,7 @@
 
     aList.push_back( MSG_PANEL_ITEM( _( "Footprint" ), module->GetReference(), DARKCYAN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Value" ), module->GetValue(), BLUE ) );
-    msg.Printf( wxT( "%8.8lX" ), module->GetTimeStamp() );
+    msg.Printf( wxT( "%8.8lX" ), (u_long)module->GetTimeStamp() );
     aList.push_back( MSG_PANEL_ITEM( _( "TimeStamp" ), msg, BROWN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Footprint Layer" ),
                      module->GetLayerName(), RED ) );
