$NetBSD: patch-source_window.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Call XtVaSetValues correctly.

--- source/window.c~	2004-09-15 22:50:58.000000000 +0000
+++ source/window.c
@@ -1157,7 +1157,7 @@ void SplitPane(WindowInfo *window)
     if (window->backlightChars)
     {
         XtVaSetValues(text, textNbacklightCharTypes,
-                window->backlightCharTypes, 0);
+                window->backlightCharTypes, (char *)NULL);
     }
     XtManageChild(text);
     window->textPanes[window->nPanes++] = text;
@@ -3016,10 +3016,10 @@ void SetBacklightChars(WindowInfo *windo
       window->backlightCharTypes = NULL;
 
     XtVaSetValues(window->textArea,
-          textNbacklightCharTypes, window->backlightCharTypes, 0);
+          textNbacklightCharTypes, window->backlightCharTypes, (char *)NULL);
     for (i=0; i<window->nPanes; i++)
       XtVaSetValues(window->textPanes[i],
-              textNbacklightCharTypes, window->backlightCharTypes, 0);
+              textNbacklightCharTypes, window->backlightCharTypes, (char *)NULL);
     if (is_applied != do_apply)
       SetToggleButtonState(window, window->backlightCharsItem, do_apply, False);
 }
