$NetBSD: patch-src_FSFileButton.c,v 1.1 2012/05/04 16:34:48 joerg Exp $

--- src/FSFileButton.c.orig	2012-05-04 13:44:22.000000000 +0000
+++ src/FSFileButton.c
@@ -689,7 +689,7 @@ createTextView(W_Screen *scr, char *text
     W_View *view = NULL;
 
     if(!text)
-	return;
+	return NULL;
 
     view = W_CreateTopView(scr);
     view->attribFlags |= CWOverrideRedirect|CWSaveUnder;
