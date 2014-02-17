$NetBSD: patch-pcbnew_kicad_plugin.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/kicad_plugin.cpp.orig	2014-02-15 15:55:03.000000000 +0100
+++ pcbnew/kicad_plugin.cpp	2014-02-15 15:56:10.000000000 +0100
@@ -673,7 +673,7 @@
     formatLayer( aDimension );
 
     if( aDimension->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aDimension->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aDimension->GetTimeStamp() );
 
     m_out->Print( 0, "\n" );
 
@@ -782,7 +782,7 @@
         m_out->Print( 0, " (width %s)", FMT_IU( aSegment->GetWidth() ).c_str() );
 
     if( aSegment->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aSegment->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aSegment->GetTimeStamp() );
 
     if( aSegment->GetStatus() )
         m_out->Print( 0, " (status %X)", aSegment->GetStatus() );
@@ -855,7 +855,7 @@
     /*  11-Nov-2021 remove if no one whines after a couple of months.  Simple graphic items
         perhaps do not need these.
     if( aModuleDrawing->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aModuleDrawing->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aModuleDrawing->GetTimeStamp() );
 
     if( aModuleDrawing->GetStatus() )
         m_out->Print( 0, " (status %X)", aModuleDrawing->GetStatus() );
@@ -879,7 +879,7 @@
     formatLayer( aTarget );
 
     if( aTarget->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aTarget->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aTarget->GetTimeStamp() );
 
     m_out->Print( 0, ")\n" );
 }
@@ -901,7 +901,7 @@
     if( !( m_ctl & CTL_OMIT_TSTAMPS ) )
     {
         m_out->Print( 0, " (tedit %lX) (tstamp %lX)\n",
-                       aModule->GetLastEditTime(), aModule->GetTimeStamp() );
+                       (u_long)aModule->GetLastEditTime(), (u_long)aModule->GetTimeStamp() );
     }
     else
         m_out->Print( 0, "\n" );
@@ -1216,7 +1216,7 @@
     formatLayer( aText );
 
     if( aText->GetTimeStamp() )
-        m_out->Print( 0, " (tstamp %lX)", aText->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aText->GetTimeStamp() );
 
     m_out->Print( 0, "\n" );
 
@@ -1324,7 +1324,7 @@
     m_out->Print( 0, " (net %d)", aTrack->GetNet() );
 
     if( aTrack->GetTimeStamp() != 0 )
-        m_out->Print( 0, " (tstamp %lX)", aTrack->GetTimeStamp() );
+        m_out->Print( 0, " (tstamp %lX)", (u_long)aTrack->GetTimeStamp() );
 
     if( aTrack->GetStatus() != 0 )
         m_out->Print( 0, " (status %X)", aTrack->GetStatus() );
@@ -1345,7 +1345,7 @@
 
     formatLayer( aZone );
 
-    m_out->Print( 0, " (tstamp %lX)", aZone->GetTimeStamp() );
+    m_out->Print( 0, " (tstamp %lX)", (u_long)aZone->GetTimeStamp() );
 
     // Save the outline aux info
     std::string hatch;
