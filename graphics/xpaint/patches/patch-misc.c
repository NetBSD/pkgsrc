$NetBSD: patch-misc.c,v 1.1 2015/10/14 20:17:27 wiz Exp $

--- misc.c.orig	2005-04-24 11:57:52.000000000 +0000
+++ misc.c
@@ -671,7 +671,7 @@ mousewheelScroll(Widget w, void * l, XEv
 	}
         else return;
         if (sb == None) return;
-#ifdef XAW3DG
+#if defined(XAW3DG) && defined(XAW_ARROW_SCROLLBARS)
         if (((ScrollbarWidget)sb)->scrollbar.scroll_mode == 2 /* if scroll continuous */
             || LookAhead (sb, event))
             return;
