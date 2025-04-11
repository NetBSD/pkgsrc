$NetBSD: patch-src_FmIcons.c,v 1.1 2025/04/11 01:49:11 nia Exp $

Fix a very obvious overflow bug.

--- src/FmIcons.c.orig	2025-04-10 23:51:35.480102112 +0000
+++ src/FmIcons.c
@@ -501,7 +501,7 @@ static void displayDTIcon(DTIconRec *dti
  }
  else
  {
-     for (i=0; i < XtNumber(file_popup_menu); i++)
+     for (i=0; i < XtNumber(popup_menu); i++)
 	 popup_menu[i].callback_data = dticon;
      dticon->popup = BuildMenu(dticon->app.form, XmMENU_POPUP, "Button Actions", 0, False, popup_menu);
      if (resources.auto_save)
