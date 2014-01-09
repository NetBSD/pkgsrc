$NetBSD: patch-kpdf_impl_SVGLengthImpl.cc,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- ksvg/impl/SVGLengthImpl.cc.orig	2005-11-08 22:25:43.000000000 +0000
+++ ksvg/impl/SVGLengthImpl.cc
@@ -395,7 +395,7 @@ float SVGLengthImpl::percentageOfViewpor
 		else if(m_mode == LENGTHMODE_HEIGHT)
 			return value * metrics.height();
 		else if(m_mode == LENGTHMODE_OTHER)
-			return value * sqrt(pow(metrics.width(), 2) + pow(metrics.height(), 2)) / sqrt(2.0);
+			return value * sqrt(pow(metrics.width(), 2.0) + pow(metrics.height(), 2.0)) / sqrt(2.0);
 	}
 
 	return 0;
