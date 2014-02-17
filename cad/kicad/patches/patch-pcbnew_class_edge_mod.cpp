$NetBSD: patch-pcbnew_class_edge_mod.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_edge_mod.cpp.orig	2014-02-15 15:51:50.000000000 +0100
+++ pcbnew/class_edge_mod.cpp	2014-02-15 15:52:10.000000000 +0100
@@ -248,7 +248,7 @@
     aList.push_back( MSG_PANEL_ITEM( _( "Graphic Item" ), wxEmptyString, DARKCYAN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Module" ), module->m_Reference->m_Text, DARKCYAN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Value" ), module->m_Value->m_Text, BLUE ) );
-    msg.Printf( wxT( "%8.8lX" ), module->GetTimeStamp() );
+    msg.Printf( wxT( "%8.8lX" ), (u_long)module->GetTimeStamp() );
     aList.push_back( MSG_PANEL_ITEM( _( "TimeStamp" ), msg, BROWN ) );
     aList.push_back( MSG_PANEL_ITEM( _( "Mod Layer" ), board->GetLayerName( module->GetLayer() ),
                                      RED ) );
