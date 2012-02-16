$NetBSD: patch-xaw.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- xaw.c.orig	2012-01-26 22:15:20.415642876 +0100
+++ xaw.c	2012-01-26 22:19:32.247692788 +0100
@@ -1330,7 +1330,7 @@ int code_erreur;
 	hand_cursor = XCreateFontCursor (XtDisplay(top), XC_hand2);
 
     if (code_erreur != 0)
-	sprintf (buf, "%s : %s", s, sys_errlist[code_erreur]);
+	sprintf (buf, "%s : %s", s, strerror(code_erreur));
     else {
       if (s[0] == '[')
 	strcpy (buf, rsc_xtel.erreur[s[1]-'0']);
