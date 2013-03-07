$NetBSD: patch-netmenu_NMwiring.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/NMwiring.c.orig	2013-03-02 23:01:19.000000000 +0000
+++ netmenu/NMwiring.c
@@ -152,8 +152,8 @@ nmwRipTileFunc(tile, plane, listHead)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMRipup()
+void
+NMRipup(void)
 {
     struct nmwarea *list;
     Rect area;
@@ -531,8 +531,8 @@ nmwNetTileFunc(tile, plane, netPtr)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMExtract()
+void
+NMExtract(void)
 {
     Rect area;
     char *net = NULL;
