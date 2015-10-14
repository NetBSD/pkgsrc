$NetBSD: patch-src_TextField.c,v 1.1 2015/10/14 20:17:28 wiz Exp $

--- src/TextField.c.orig	2000-04-04 15:05:36.000000000 +0000
+++ src/TextField.c
@@ -705,11 +705,6 @@ TextFieldClassRec textFieldClassRec = {
   { /* simple    fields */
     /* change_sensitive */		XtInheritChangeSensitive
   },
-#ifdef XAW3D
-  { /* ThreeD class fields */
-    /* shadowdraw	*/		(void(*)())TfwDrawShadows
-  },
-#endif
   { /* textField fields */
     /* empty			*/	0
   }
@@ -2315,11 +2310,6 @@ ReDisplay(tfw,False);
 if (TF.label)
 	DrawLabel(tfw,False);
 
-#ifdef XAW3D
- (*((TextFieldWidgetClass)(XtClass((Widget)tfw)))->threeD_class.shadowdraw)(w,ev,reg,
-		(Boolean)(! (tfw->core.sensitive && !TF.readonly)));
-#endif
-
 }
 
 #ifdef XAW3D
