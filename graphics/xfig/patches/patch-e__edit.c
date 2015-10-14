$NetBSD: patch-e__edit.c,v 1.1 2015/10/14 20:17:26 wiz Exp $

--- e_edit.c.orig	2007-04-04 16:18:32.000000000 +0000
+++ e_edit.c
@@ -4247,10 +4247,6 @@ str_panel(char *string, char *name, Widg
     NextArg(XtNbottom, XtChainBottom);
     NextArg(XtNleft, XtChainLeft);
     NextArg(XtNright, XtChainRight);
-#ifdef I18N
-    if (!appres.international || !international)
-      NextArg(XtNinternational, False);
-#endif /* I18N */
     *pi_x = XtCreateManagedWidget(textname, asciiTextWidgetClass, form, Args, ArgCount);
 
     /* make CR do nothing for now */
