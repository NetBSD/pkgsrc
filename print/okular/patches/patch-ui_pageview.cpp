$NetBSD: patch-ui_pageview.cpp,v 1.1 2015/01/06 11:40:33 jperkin Exp $

Avoid ambiguous overloaded function call.

--- ui/pageview.cpp.orig	2014-11-06 22:38:13.000000000 +0000
+++ ui/pageview.cpp
@@ -2351,7 +2351,7 @@ void PageView::mouseReleaseEvent( QMouse
                         double distance = 0.0;
                         rect = pageItem->page()->nearestObjectRect( Okular::ObjectRect::SourceRef, nX, nY, pageItem->uncroppedWidth(), pageItem->uncroppedHeight(), &distance );
                         // distance is distanceSqr, adapt it to a normalized value
-                        distance = distance / (pow( pageItem->uncroppedWidth(), 2 ) + pow( pageItem->uncroppedHeight(), 2 ));
+                        distance = distance / (pow( (float)pageItem->uncroppedWidth(), 2.0 ) + pow( (float)pageItem->uncroppedHeight(), 2.0 ));
                         if ( rect && ( distance > s_minDistance ) )
                             rect = 0;
                     }
