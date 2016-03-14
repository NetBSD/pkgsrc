$NetBSD: patch-src_chcanv.cpp,v 1.1 2016/03/14 11:01:06 bouyer Exp $
From master:
https://github.com/OpenCPN/OpenCPN/commit/39c0b7c3367181ed92adfe0e41d59b7fb65d3a9a

--- src/chcanv.cpp.orig
+++ src/chcanv.cpp
@@ -10172,6 +10172,11 @@ void ChartCanvas::DrawAllRoutesInBBox( ocpnDC& dc, LLBBox& BltBBox, const wxRegi
                 continue;
             }
 
+            if ( 0 == pRouteDraw->GetnPoints() ) {
+                node = node->GetNext();
+                continue;
+            }
+            
             LLBBox test_box = pRouteDraw->GetBBox();
 
             if( b_run ) test_box.Expand( gLon, gLat );
