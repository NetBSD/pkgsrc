$NetBSD: patch-netmenu_NMwiring.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

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
$NetBSD: patch-netmenu_NMwiring.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

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
