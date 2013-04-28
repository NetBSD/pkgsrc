$NetBSD: patch-source_text.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call XtVaGetValues correctly.

--- source/text.c~	2004-07-28 18:02:03.000000000 +0000
+++ source/text.c
@@ -3126,7 +3126,7 @@ static void pageRightAP(Widget w, XEvent
     cancelDrag(w);
     if (hasKey("scrollbar", args, nArgs)) {
         XtVaGetValues(textD->hScrollBar, XmNmaximum, &sliderMax, 
-    	    XmNsliderSize, &sliderSize, 0);
+    	    XmNsliderSize, &sliderSize, (char*)NULL);
 	horizOffset = min(textD->horizOffset + textD->width, sliderMax - sliderSize);
 	if (textD->horizOffset == horizOffset) {
             ringIfNecessary(silent, w);
@@ -3218,7 +3218,7 @@ static void scrollLeftAP(Widget w, XEven
     if (*nArgs == 0 || sscanf(args[0], "%d", &nPixels) != 1)
     	return;
     XtVaGetValues(textD->hScrollBar, XmNmaximum, &sliderMax, 
-   	XmNsliderSize, &sliderSize, 0);
+   	XmNsliderSize, &sliderSize, (char *)NULL);
     horizOffset = min(max(0, textD->horizOffset - nPixels), sliderMax - sliderSize);
     if (textD->horizOffset != horizOffset) {
 	TextDSetScroll(textD, textD->topLineNum, horizOffset);
@@ -3235,7 +3235,7 @@ static void scrollRightAP(Widget w, XEve
     if (*nArgs == 0 || sscanf(args[0], "%d", &nPixels) != 1)
     	return;
     XtVaGetValues(textD->hScrollBar, XmNmaximum, &sliderMax, 
-    	    XmNsliderSize, &sliderSize, 0);
+    	    XmNsliderSize, &sliderSize, (char *)NULL);
     horizOffset = min(max(0, textD->horizOffset + nPixels), sliderMax - sliderSize);
     if (textD->horizOffset != horizOffset) {
 	TextDSetScroll(textD, textD->topLineNum, horizOffset);
