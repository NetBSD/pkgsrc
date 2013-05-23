$NetBSD: patch-curses_cursescontainer.H,v 1.1 2013/05/23 15:05:54 joerg Exp $

--- curses/cursescontainer.H.orig	2013-05-22 19:38:54.000000000 +0000
+++ curses/cursescontainer.H
@@ -31,8 +31,6 @@ class CursesContainer : public Curses {
 
 	std::vector<Child> children;
 
-	std::vector<Child>::iterator drawIndex;
-
 public:
 	friend class Curses;
 
