$NetBSD: patch-pcbnew_class_zone.cpp,v 1.2 2016/02/03 19:34:34 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_zone.cpp.orig	2015-12-11 18:03:57.000000000 +0100
+++ pcbnew/class_zone.cpp	2015-12-11 18:04:13.000000000 +0100
@@ -818,7 +818,7 @@
     if( GetIsKeepout() )
         text << wxT( " " ) << _( "(Keepout)" );
 
-    text << wxString::Format( wxT( " (%08lX)" ), m_TimeStamp );
+    text << wxString::Format( wxT( " (%08lX)" ), (u_long)m_TimeStamp );
 
     // Display net name for copper zones
     if( !GetIsKeepout() )
@@ -852,4 +852,4 @@
                  GetChars( GetLayerName() ) );
 
     return msg;
-}
\ No newline at end of file
+}
