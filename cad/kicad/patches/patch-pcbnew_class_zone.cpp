$NetBSD: patch-pcbnew_class_zone.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_zone.cpp.orig	2014-02-15 15:42:53.000000000 +0100
+++ pcbnew/class_zone.cpp	2014-02-15 15:43:00.000000000 +0100
@@ -946,7 +946,7 @@
         text << wxT( " " ) << _( "(Keepout)" );
 
     text << wxT( " " );
-    text << wxString::Format( wxT( "(%08lX)" ), m_TimeStamp );
+    text << wxString::Format( wxT( "(%08lX)" ), (u_long)m_TimeStamp );
 
     // Display net name for copper zones
     if( !GetIsKeepout() )
