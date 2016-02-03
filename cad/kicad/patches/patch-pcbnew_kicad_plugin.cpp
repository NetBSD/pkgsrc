$NetBSD: patch-pcbnew_kicad_plugin.cpp,v 1.2 2016/02/03 19:34:34 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/kicad_plugin.cpp.orig	2015-12-11 18:05:12.000000000 +0100
+++ pcbnew/kicad_plugin.cpp	2015-12-11 18:14:06.000000000 +0100
@@ -770,7 +770,7 @@
     formatLayer( aDimension );
 
     if( aDimension->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aDimension->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aDimension->GetTimeStamp() );
 
     m_out->Print( 0, "\n" );
 
@@ -879,7 +879,7 @@
         m_out->Print( 0, " (width %s)", FMT_IU( aSegment->GetWidth() ).c_str() );
 
     if( aSegment->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aSegment->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aSegment->GetTimeStamp() );
 
     if( aSegment->GetStatus() )
         m_out->Print( 0, " (status %X)", aSegment->GetStatus() );
@@ -966,7 +966,7 @@
     formatLayer( aTarget );
 
     if( aTarget->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aTarget->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aTarget->GetTimeStamp() );
 
     m_out->Print( 0, ")\n" );
 }
@@ -1003,7 +1003,7 @@
 
     if( !( m_ctl & CTL_OMIT_TSTAMPS ) )
     {
-        m_out->Print( 0, " (tstamp %lX)\n", aModule->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)\n", (u_long)aModule->GetTimeStamp() );
     }
     else
         m_out->Print( 0, "\n" );
@@ -1344,7 +1344,7 @@
     formatLayer( aText );
 
     if( aText->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aText->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aText->GetTimeStamp() );
 
     m_out->Print( 0, "\n" );
 
@@ -1452,7 +1452,7 @@
     m_out->Print( 0, " (net %d)", m_mapping->Translate( aTrack->GetNetCode() ) );
 
     if( aTrack->GetTimeStamp() != 0 )
-        m_out->Print( 0, " (tstamp %lX)", aTrack->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aTrack->GetTimeStamp() );
 
     if( aTrack->GetStatus() != 0 )
         m_out->Print( 0, " (status %X)", aTrack->GetStatus() );
@@ -1473,7 +1473,7 @@
 
     formatLayer( aZone );
 
-    m_out->Print( 0, " (tstamp %lX)", aZone->GetTimeStamp() );
+    m_out->Print( 0, " (tstamp %lX)", (u_long)aZone->GetTimeStamp() );
 
     // Save the outline aux info
     std::string hatch;
