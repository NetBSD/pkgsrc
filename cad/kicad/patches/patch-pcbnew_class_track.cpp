$NetBSD: patch-pcbnew_class_track.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_track.cpp.orig	2014-02-15 15:42:13.000000000 +0100
+++ pcbnew/class_track.cpp	2014-02-15 15:42:23.000000000 +0100
@@ -161,7 +161,7 @@
     NETINFO_ITEM* net;
     BOARD* board = GetBoard();
 
-    text << _( "Zone" ) << wxT( " " ) << wxString::Format( wxT( "(%08lX)" ), m_TimeStamp );
+    text << _( "Zone" ) << wxT( " " ) << wxString::Format( wxT( "(%08lX)" ), (u_long)m_TimeStamp );
 
     if( board )
     {
