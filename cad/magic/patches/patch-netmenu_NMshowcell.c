$NetBSD: patch-netmenu_NMshowcell.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

--- netmenu/NMshowcell.c.orig	2013-03-02 22:58:33.000000000 +0000
+++ netmenu/NMshowcell.c
@@ -77,13 +77,8 @@ static CellDef *nmscShowDef = NULL;
 static Plane *nmscPlane;	/* Shared between procs below. */
 extern int nmscRedrawFunc();	/* Forward declaration. */
 
-int
-NMRedrawCell(window, plane)
-    MagWindow *window;		/* Window in which to redisplay. */
-    Plane *plane;		/* Non-space tiles on this plane indicate,
-				 * in root cell coordinates, the areas where
-				 * highlight information must be redrawn.
-				 */
+void
+NMRedrawCell(MagWindow *window, Plane *plane)
 {
     int i;
     Rect area;
@@ -319,9 +314,8 @@ NMShowUnderBox()
  * ----------------------------------------------------------------------------
  */
 
-int
-NMShowRoutedNet(netName)
-    char * netName;
+void
+NMShowRoutedNet(char *netName)
 {
     int nmShowRoutedNetFunc();
 
$NetBSD: patch-netmenu_NMshowcell.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

--- netmenu/NMshowcell.c.orig	2013-03-02 22:58:33.000000000 +0000
+++ netmenu/NMshowcell.c
@@ -77,13 +77,8 @@ static CellDef *nmscShowDef = NULL;
 static Plane *nmscPlane;	/* Shared between procs below. */
 extern int nmscRedrawFunc();	/* Forward declaration. */
 
-int
-NMRedrawCell(window, plane)
-    MagWindow *window;		/* Window in which to redisplay. */
-    Plane *plane;		/* Non-space tiles on this plane indicate,
-				 * in root cell coordinates, the areas where
-				 * highlight information must be redrawn.
-				 */
+void
+NMRedrawCell(MagWindow *window, Plane *plane)
 {
     int i;
     Rect area;
@@ -319,9 +314,8 @@ NMShowUnderBox()
  * ----------------------------------------------------------------------------
  */
 
-int
-NMShowRoutedNet(netName)
-    char * netName;
+void
+NMShowRoutedNet(char *netName)
 {
     int nmShowRoutedNetFunc();
 
