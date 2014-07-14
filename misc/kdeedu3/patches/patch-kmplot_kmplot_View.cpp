$NetBSD: patch-kmplot_kmplot_View.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kmplot/kmplot/View.cpp.orig	2006-05-22 18:03:40.000000000 +0000
+++ kmplot/kmplot/View.cpp
@@ -890,7 +890,7 @@ void View::mousePressEvent(QMouseEvent *
 				if ( function_type=='x' &&  fabs(csxpos-m_parser->fkt(it, csxpos))< g && it->fstr.contains('t')==1) //parametric plot
 				{
 					QValueVector<Ufkt>::iterator ufkt_y = it+1;
-					if ( fabs(csypos-m_parser->fkt(ufkt_y, csxpos)<g)  && ufkt_y->fstr.contains('t')==1)
+					if ( fabs(csypos-m_parser->fkt(ufkt_y, csxpos)) < g && ufkt_y->fstr.contains('t')==1)
 					{
 						if ( csmode == -1)
 						{
