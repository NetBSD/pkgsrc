$NetBSD: patch-src_TextField.c,v 1.2 2020/02/24 21:45:24 bouyer Exp $

--- src/TextField.c.orig	2020-02-24 17:23:51.228109581 +0100
+++ src/TextField.c	2020-02-24 17:24:38.970387116 +0100
@@ -662,11 +662,7 @@
 
 TextFieldClassRec textFieldClassRec = {
   { /* core fields */
-#ifdef XAW3D
-    /* superclass		*/	(WidgetClass) &threeDClassRec,
-#else
     /* superclass		*/	(WidgetClass) &simpleClassRec,
-#endif
     /* class_name		*/	"TextField",
     /* widget_size		*/	sizeof(TextFieldRec),
     /* class_initialize		*/	ClassInitialize,
@@ -702,11 +698,6 @@
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
@@ -2312,11 +2303,6 @@
 if (TF.label)
 	DrawLabel(tfw,False);
 
-#ifdef XAW3D
- (*((TextFieldWidgetClass)(XtClass((Widget)tfw)))->threeD_class.shadowdraw)(w,ev,reg,
-		(Boolean)(! (tfw->core.sensitive && !TF.readonly)));
-#endif
-
 }
 
 #ifdef XAW3D
