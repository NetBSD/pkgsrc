$NetBSD: patch-src_ocpn_draw_pi.cpp,v 1.1 2016/05/23 08:55:15 bouyer Exp $
https://github.com/jongough/ocpn_draw_pi/issues/250

--- src/ocpn_draw_pi.cpp.orig	2016-04-13 08:28:11.000000000 +0200
+++ src/ocpn_draw_pi.cpp	2016-05-22 12:46:48.678028290 +0200
@@ -217,7 +217,6 @@
 
 PlugIn_ViewPort *g_pVP;
 PlugIn_ViewPort g_VP;
-ODDC          *g_pDC;
 bool            g_bShowMag;
 double          g_dVar;
 double          g_UserVar;
@@ -2385,6 +2384,7 @@
         format = wxS("%4.0f ");
     }
     result << wxString::Format(format, usrDistance ) << *sUnit;
+    delete sUnit;
     return result;
 }
 void ocpn_draw_pi::latlong_to_chartpix(double lat, double lon, double &pixx, double &pixy) 
@@ -2417,14 +2417,14 @@
     m_chart_scale = pivp->chart_scale;
     m_view_scale = pivp->view_scale_ppm;
     
-    g_pDC = new ODDC( dc );
+    ODDC g_pDC(dc);
     LLBBox llbb;
     llbb.SetMin( pivp->lon_min, pivp->lat_min );
     llbb.SetMax( pivp->lon_max, pivp->lat_max );
     
-    DrawAllPathsInBBox( *g_pDC, llbb );
-    DrawAllODPointsInBBox( *g_pDC, llbb );
-    RenderPathLegs( *g_pDC );
+    DrawAllPathsInBBox( g_pDC, llbb );
+    DrawAllODPointsInBBox( g_pDC, llbb );
+    RenderPathLegs( g_pDC );
     
     return TRUE;
 }
@@ -2438,20 +2438,20 @@
     m_chart_scale = pivp->chart_scale;
     m_view_scale = pivp->view_scale_ppm;
     
-    g_pDC = new ODDC();
+    ODDC g_pDC;
     LLBBox llbb;
     llbb.SetMin( pivp->lon_min, pivp->lat_min );
     llbb.SetMax( pivp->lon_max, pivp->lat_max );
     
     //    DrawAllODPointsInBBox( *g_pDC, llbb );
-    RenderPathLegs( *g_pDC );
+    RenderPathLegs( g_pDC );
     
     if (m_pMouseBoundary) m_pMouseBoundary->DrawGL( *pivp );
     
     DrawAllPathsAndODPoints( *pivp );
 
     if( g_pODRolloverWin && g_pODRolloverWin->IsActive() && g_pODRolloverWin->GetBitmap() != NULL ) {
-        g_pDC->DrawBitmap( *(g_pODRolloverWin->GetBitmap()),
+        g_pDC.DrawBitmap( *(g_pODRolloverWin->GetBitmap()),
                        g_pODRolloverWin->GetPosition().x,
                        g_pODRolloverWin->GetPosition().y, false );
     }
