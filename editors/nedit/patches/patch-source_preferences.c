$NetBSD: patch-source_preferences.c,v 1.2 2014/03/22 17:26:13 gdt Exp $

Silence gcc warnings about unsafe pointer casts.

--- source/preferences.c.orig	2004-08-20 19:33:20.000000000 +0000
+++ source/preferences.c
@@ -59,6 +59,7 @@ static const char CVSID[] = "$Id: prefer
 #include <string.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <stdint.h>
 #ifdef VMS
 #include "../util/VMSparam.h"
 #else
@@ -2161,7 +2162,7 @@ void SetLanguageMode(WindowInfo *window,
 	XtVaGetValues(menu, XmNchildren, &items, XmNnumChildren, &nItems, NULL);
 	for (n=0; n<(int)nItems; n++) {
     	    XtVaGetValues(items[n], XmNuserData, &userData, NULL);
-    	    XmToggleButtonSetState(items[n], (int)userData == mode, False);
+    	    XmToggleButtonSetState(items[n], (intptr_t)userData == mode, False);
 	}
     }
 }
@@ -4946,7 +4947,7 @@ static void updateLanguageModeSubmenu(Wi
             	xmToggleButtonGadgetClass, menu,
             	XmNlabelString, s1=XmStringCreateSimple(LanguageModes[i]->name),
  	    	XmNmarginHeight, 0,
-   		XmNuserData, (void *)i,
+   		XmNuserData, (void *)(intptr_t)i,
     		XmNset, window->languageMode==i, NULL);
         XmStringFree(s1);
 	XtAddCallback(btn, XmNvalueChangedCallback, setLangModeCB, window);
@@ -4967,14 +4968,14 @@ static void setLangModeCB(Widget w, XtPo
     XtVaGetValues(w, XmNuserData, &mode, NULL);
     
     /* If the mode didn't change, do nothing */
-    if (window->languageMode == (int)mode)
+    if (window->languageMode == (intptr_t)mode)
     	return;
     
     /* redo syntax highlighting word delimiters, etc. */
 /*
     reapplyLanguageMode(window, (int)mode, False);
 */
-    params[0] = (((int)mode) == PLAIN_LANGUAGE_MODE) ? "" : LanguageModes[(int)mode]->name;
+    params[0] = (((intptr_t)mode) == PLAIN_LANGUAGE_MODE) ? "" : LanguageModes[(intptr_t)mode]->name;
     XtCallActionProc(window->textArea, "set_language_mode", NULL, params, 1);
 }
 
