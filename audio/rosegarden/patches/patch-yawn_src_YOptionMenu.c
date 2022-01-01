$NetBSD: patch-yawn_src_YOptionMenu.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- yawn/src/YOptionMenu.c~	1996-07-18 21:03:25.000000000 +0000
+++ yawn/src/YOptionMenu.c
@@ -48,7 +48,7 @@ void _YOptionMenuCallback(Widget w, XtPo
 	XtVaSetValues(optionMenus[i].button, XtNlabel, elt->label, NULL);
 	if (optionMenus[i].callback) {
 	  optionMenus[i].callback(optionMenus[i].button,
-				  optionMenus[i].client_data, (XtPointer)j);
+				  optionMenus[i].client_data, (XtPointer)(intptr_t)j);
 	}
 
 	End;
