$NetBSD: patch-pgadmin_gqb_gqbView.cpp,v 1.1 2013/07/20 05:10:42 richard Exp $

patch to quelch g++ warning 

--- pgadmin/gqb/gqbView.cpp.orig	2012-08-02 14:29:01.000000000 +0000
+++ pgadmin/gqb/gqbView.cpp
@@ -341,7 +341,7 @@ void gqbView::onMotion(wxMouseEvent &eve
 		}
 		else
 		{
-			anySelected = false;
+			anySelected = NULL;
 			mode = pt_normal;
 		}
 
