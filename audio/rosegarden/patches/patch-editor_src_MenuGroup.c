$NetBSD: patch-editor_src_MenuGroup.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Use standard headers.
Use ctype functions correctly.
Use scratch buffers that are large enough.
Don't use sprintf().

--- editor/src/MenuGroup.c~	1997-02-28 15:12:32.000000000 +0000
+++ editor/src/MenuGroup.c
@@ -6,6 +6,8 @@
 
 /* {{{ Includes */
 
+#include <ctype.h>
+
 #include "General.h"
 #include "Widgets.h"
 #include "Menu.h"
@@ -471,9 +473,9 @@ void GroupMenuTuplet(Widget w, XtPointer
 
       for (m = 0; choices[nch].description[m]; ++m) {
 	if (choices[nch].description[m] == ' ') {
-	  if (isupper(choices[nch].description[m+1])) {
+	  if (isupper((unsigned char)choices[nch].description[m+1])) {
 	    choices[nch].description[m+1] =
-	      tolower(choices[nch].description[m+1]);
+	      tolower((unsigned char)choices[nch].description[m+1]);
 	  }
 	}
       }
@@ -972,7 +974,7 @@ void GroupMenuInvert(Widget w, XtPointer
   Dimension      w1;
   XPoint         op;
   String         temp;
-  char           title[32];
+  char           title[64];
   int            i, result = -1;
 
   MajorStaveRec *mstave  = (MajorStaveRec *)stave;
@@ -997,9 +999,9 @@ void GroupMenuInvert(Widget w, XtPointer
 				tPane, MediumShade);
 
   switch(scope) {
-  case 1:  sprintf(title, "Invert Area around pitch");          break;
-  case 2:  sprintf(title, "Invert Rest of Staff around pitch"); break;
-  default: sprintf(title, "Invert Whole Piece around pitch");   break;
+  case 1:  snprintf(title, sizeof(title), "Invert Area around pitch");          break;
+  case 2:  snprintf(title, sizeof(title), "Invert Rest of Staff around pitch"); break;
+  default: snprintf(title, sizeof(title), "Invert Whole Piece around pitch");   break;
   }
 
   tLabel     = YCreateLabel(title, tTopBox);
