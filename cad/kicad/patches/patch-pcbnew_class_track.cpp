$NetBSD: patch-pcbnew_class_track.cpp,v 1.4 2019/06/08 11:04:28 rillig Exp $

64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/class_track.cpp.orig	2015-12-11 18:02:48.000000000 +0100
+++ pcbnew/class_track.cpp	2015-12-11 18:03:02.000000000 +0100
@@ -143,7 +143,7 @@
     }
 
     text.Printf( _( "Zone (%08lX) [%s] on %s" ),
-                 m_TimeStamp, GetChars( nettxt ), GetChars( GetLayerName() ) );
+                 (u_long)m_TimeStamp, GetChars( nettxt ), GetChars( GetLayerName() ) );
 
     return text;
 }
