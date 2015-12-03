$NetBSD: patch-src_Scrollbar.c,v 1.1 2015/12/03 17:34:56 leot Exp $

Fix compilation error with Xaw-Xpm:

 http://git.savannah.gnu.org/cgit/gv.git/commit/gv/src?id=0155aaac7a2e87e253f9203944808388ecffe9a3

--- src/Scrollbar.c.orig	2012-04-01 14:43:24.000000000 +0000
+++ src/Scrollbar.c
@@ -1006,7 +1006,11 @@ static void Redisplay(Widget w, XEvent *
    TOPLOC = newtop;
    SHOWNLENGTH = newbot-newtop+1;
 
+#if defined(XtRRelief)
    (*swclass->threeD_class.shadowdraw) (w, event, region, sbw->threeD.relief, FALSE);
+#else
+   (*swclass->threeD_class.shadowdraw) (w, event, region, FALSE);
+#endif
 
    ENDMESSAGE(Redisplay)
 }
