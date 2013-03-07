$NetBSD: patch-netmenu_nmInt.h,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/nmInt.h.orig	2006-04-10 22:03:14.000000000 +0000
+++ netmenu/nmInt.h
@@ -24,6 +24,8 @@
 #define _NMINT_H
 
 #include "windows/windows.h"
+#include "textio/txcommands.h"
+#include "tiles/tile.h"
 
 /* The declarations below define the elements displayed in the
  * net-list menu.  There are three kinds of things:
@@ -108,26 +110,30 @@ extern void NMAddPoint();
 extern void NMDeletePoint();
 extern void NMClearPoints();
 extern void NMUpdatePoints();
-extern int NMRedrawPoints();
 
-extern int NMRedrawCell();
 extern void NMShowCell();
 extern void NMUnsetCell();
 extern void NMShowUnderBox();
-extern int NMShowRoutedNet();
 extern void NMShowLabel();
 
-extern int NMRipup();
 extern int NMRipupList();
-extern int NMExtract();
 extern void NMSelectNet();
 
 extern bool NMCheckWritten();
-extern int NMWriteAll();
 
 extern void NMUndo();
 extern void NMUndoInit();
 
+void NMcommand(MagWindow *w, TxCommand *cmd);
+void NMredisplay(MagWindow *w, Rect *rootArea, Rect *clipArea);
+void NMDeleteTerm(char *name);
+void NMWriteAll(void);
+void NMRedrawPoints(MagWindow *window, Plane *plane);
+void NMRedrawCell(MagWindow *window, Plane *plane);
+void NMShowRoutedNet(char *netName);
+void NMRipup(void);
+void NMExtract(void);
+
 /* Various global variables (within this module): */
 
 extern char * NMCurNetName;
