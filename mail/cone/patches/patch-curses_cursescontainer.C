$NetBSD: patch-curses_cursescontainer.C,v 1.1 2013/05/23 15:05:54 joerg Exp $

--- curses/cursescontainer.C.orig	2013-05-22 19:38:08.000000000 +0000
+++ curses/cursescontainer.C
@@ -10,7 +10,7 @@
 using namespace std;
 
 CursesContainer::CursesContainer(CursesContainer *parent)
-	: Curses(parent), drawIndex(0)
+	: Curses(parent)
 {
 }
 
