$NetBSD: patch-Xlt_SlideC.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Don't use NULL as an integer constant.

--- Xlt/SlideC.c~	2003-12-25 06:55:07.000000000 +0000
+++ Xlt/SlideC.c
@@ -116,14 +116,14 @@ XltSlideContextClassRec xltSlideContextC
 /* notify that initialize called    XtArgsProc        */ NULL,
 /* NULL                             XtProc            */ NULL,
 /* NULL                             XtPointer         */ NULL,
-/* NULL                             Cardinal          */ (Cardinal)NULL,
+/* NULL                             Cardinal          */ (Cardinal)0,
 /* resources for subclass fields    XtResourceList    */ resources,
 /* number of entries in resources   Cardinal          */ XtNumber(resources),
 /* resource class quarkified        XrmClass          */ NULLQUARK,
-/* NULL                             Boolean           */ (Boolean)NULL,
-/* NULL                             XtEnum            */ (XtEnum)NULL,
-/* NULL				    Boolean           */ (Boolean)NULL,
-/* NULL                             Boolean           */ (Boolean)NULL,
+/* NULL                             Boolean           */ (Boolean)0,
+/* NULL                             XtEnum            */ (XtEnum)0,
+/* NULL				    Boolean           */ (Boolean)0,
+/* NULL                             Boolean           */ (Boolean)0,
 /* free data for subclass pointers  XtWidgetProc      */ destroy,
 /* NULL                             XtProc            */ NULL,
 /* NULL			            XtProc            */ NULL,
