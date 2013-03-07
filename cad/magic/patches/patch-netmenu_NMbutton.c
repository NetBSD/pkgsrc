$NetBSD: patch-netmenu_NMbutton.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/NMbutton.c.orig	2013-03-02 22:48:07.000000000 +0000
+++ netmenu/NMbutton.c
@@ -79,7 +79,7 @@ NMButtonNetList(window, cmd, nmButton, p
     else
     {
 	TxPrintf("New net list name: ");
-	if (TxGetLine(newName, MAXLENGTH) == NULL) newName[0] == 0;
+	if (TxGetLine(newName, MAXLENGTH) == NULL) newName[0] = 0;
 	if (newName[0] == 0) return;
 	NMNewNetlist(newName);
     }
