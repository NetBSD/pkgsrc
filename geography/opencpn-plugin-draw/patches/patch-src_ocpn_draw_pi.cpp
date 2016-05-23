$NetBSD: patch-src_ocpn_draw_pi.cpp,v 1.2 2016/05/23 13:10:15 bouyer Exp $
https://github.com/jongough/ocpn_draw_pi/issues/250

--- src/ocpn_draw_pi.cpp.orig	2016-04-13 08:28:11.000000000 +0200
+++ src/ocpn_draw_pi.cpp	2016-05-23 14:51:23.159399881 +0200
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
@@ -2461,8 +2461,6 @@
 
 void ocpn_draw_pi::RenderPathLegs( ODDC &dc ) 
 {
-    ODDC tdc( dc );
-    
     if( nBoundary_State >= 2) {
         
         Boundary* boundary = 0;
@@ -2492,7 +2490,7 @@
         }
         
         //        if( !IsTouchInterface_PlugIn) {
-        boundary->DrawPointWhich( tdc, boundary->m_lastMousePointIndex, &lastPoint );
+        boundary->DrawPointWhich( dc, boundary->m_lastMousePointIndex, &lastPoint );
         if( boundary->m_NextLegGreatCircle ) {
             for( int i=1; i<=milesDiff; i++ ) {
                 double p = (double)i * (1.0/(double)milesDiff);
@@ -2500,24 +2498,24 @@
                 Geodesic::GreatCircleTravel( m_prev_rlon, m_prev_rlat, gcDist*p, brg, &pLon, &pLat, &gcBearing2 );
                 GetCanvasPixLL( m_pVP, &destPoint, m_cursor_lat, m_cursor_lon);
                 //destPoint = VPoint.GetPixFromLL( pLat, pLon );
-                boundary->DrawSegment( tdc, &lastPoint, &destPoint, *m_pVP, false );
+                boundary->DrawSegment( dc, &lastPoint, &destPoint, *m_pVP, false );
                 wxPoint rpn;
-                boundary->GetPoint( 1 )->Draw( tdc, &rpn );
-                boundary->DrawSegment( tdc, &rpn , &destPoint, *m_pVP, false );
+                boundary->GetPoint( 1 )->Draw( dc, &rpn );
+                boundary->DrawSegment( dc, &rpn , &destPoint, *m_pVP, false );
                 lastPoint = destPoint;
             }
         }
         else {
-            boundary->DrawSegment( tdc, &lastPoint, &r_rband, *m_pVP, false );
+            boundary->DrawSegment( dc, &lastPoint, &r_rband, *m_pVP, false );
             if ( nBoundary_State >= 2) { 
                 wxPoint rpn;
-                boundary->GetPoint( 1 )->Draw( tdc, &rpn );
-                boundary->DrawSegment( tdc, &rpn , &r_rband, *m_pVP, false );
+                boundary->GetPoint( 1 )->Draw( dc, &rpn );
+                boundary->DrawSegment( dc, &rpn , &r_rband, *m_pVP, false );
             }
         }
         
-        wxString info = CreateExtraPathLegInfo(tdc, boundary, brg, dist, m_cursorPoint);
-        RenderExtraPathLegInfo( tdc, r_rband, info );
+        wxString info = CreateExtraPathLegInfo(dc, boundary, brg, dist, m_cursorPoint);
+        RenderExtraPathLegInfo( dc, r_rband, info );
     } else if( nEBL_State > 0 || m_bEBLMoveOrigin ) {
         EBL *ebl = new EBL();
         double brg, dist;
@@ -2526,19 +2524,17 @@
             ODPoint *tp = (ODPoint *) m_pSelectedEBL->m_pODPointList->GetLast()->GetData();
             GetCanvasPixLL( g_pVP, &tpoint, tp->m_lat, tp->m_lon );
             DistanceBearingMercator_Plugin( m_cursor_lat, m_cursor_lon, tp->m_lat, tp->m_lon, &brg, &dist );
-            ebl->DrawSegment( tdc, &tpoint, &m_cursorPoint, *m_pVP, false );
+            ebl->DrawSegment( dc, &tpoint, &m_cursorPoint, *m_pVP, false );
         } else {
             GetCanvasPixLL( g_pVP, &tpoint, g_pfFix.Lat, g_pfFix.Lon );
             DistanceBearingMercator_Plugin( m_cursor_lat, m_cursor_lon, g_pfFix.Lat, g_pfFix.Lon, &brg, &dist );
-            ebl->DrawSegment( tdc, &tpoint, &m_cursorPoint, *m_pVP, false );
+            ebl->DrawSegment( dc, &tpoint, &m_cursorPoint, *m_pVP, false );
         }
-        wxString info = CreateExtraPathLegInfo(tdc, ebl, brg, dist, m_cursorPoint);
+        wxString info = CreateExtraPathLegInfo(dc, ebl, brg, dist, m_cursorPoint);
         if(info.length() > 0)
-            RenderExtraPathLegInfo( tdc, m_cursorPoint, info );
+            RenderExtraPathLegInfo( dc, m_cursorPoint, info );
         delete ebl;
     }
-        
-        
 }
 
 wxString ocpn_draw_pi::CreateExtraPathLegInfo(ODDC &dc, ODPath *path, double brg, double dist, wxPoint ref_point)
