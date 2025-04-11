$NetBSD: patch-src_FmFwActions.c,v 1.1 2025/04/11 01:49:11 nia Exp $

64-bit support.

--- src/FmFwActions.c.orig	2025-04-10 23:50:02.567715369 +0000
+++ src/FmFwActions.c
@@ -188,7 +188,7 @@ void filePopup(Widget w, XEvent *event, 
  FileWindowRec *fw;
  int x, y, x_win, y_win;
  unsigned int mask;
- int item;
+ long item;
 
  fw = findFileWidgetByForm(w);
  if (!fw || fw->scrolled == None)  return;
