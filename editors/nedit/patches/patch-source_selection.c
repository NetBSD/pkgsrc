$NetBSD: patch-source_selection.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call <ctype.h> functions correctly.

--- source/selection.c~	2004-08-01 10:06:11.000000000 +0000
+++ source/selection.c
@@ -563,7 +563,7 @@ void AddMark(WindowInfo *window, Widget 
     
     /* look for a matching mark to re-use, or advance
        nMarks to create a new one */
-    label = toupper(label);
+    label = toupper((unsigned char)label);
     for (index=0; index<window->nMarks; index++) {
     	if (window->markTable[index].label == label)
    	    break;
@@ -588,7 +588,7 @@ void GotoMark(WindowInfo *window, Widget
     selection *sel, *oldSel;
     
     /* look up the mark in the mark table */
-    label = toupper(label);
+    label = toupper((unsigned char)label);
     for (index=0; index<window->nMarks; index++) {
     	if (window->markTable[index].label == label)
    	    break;
