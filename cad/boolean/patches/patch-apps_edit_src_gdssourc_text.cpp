$NetBSD: patch-apps_edit_src_gdssourc_text.cpp,v 1.2 2019/06/08 11:04:27 rillig Exp $

--- apps/edit/src/gdssourc/text.cpp.orig	2012-10-20 11:58:47.000000000 +0000
+++ apps/edit/src/gdssourc/text.cpp
@@ -61,9 +61,10 @@ void Text::DoWrite(DrawDriver& dr)
 
 	dr.SetSelected(GetSelect());
 
+   wxTransformMatrix tmp(*dr.GetMatrix() * *GetRelativeMatrix());
    dr.GDSDrawText(_text, min_point.GetX(), min_point.GetY(),
 										  max_point.GetX(), max_point.GetY(),
-								   	  this, &(*dr.GetMatrix() * *GetRelativeMatrix()));
+								   	  this, &tmp);
 
 }
 
