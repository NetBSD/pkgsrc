$NetBSD: patch-src_ncu.cxx,v 1.2 2019/11/09 11:22:20 nia Exp $

(from the commit log)
date: 2010-02-25 03:08:12 +0900;  author: drochner;  state: Exp;
 Set the keyboard mode to raw() explicitely. ncurses seems to do
 this in some magical way, didn't find a hint in documentation.

--- src/ncu.cxx.orig	2019-11-05 11:06:41.000000000 +0000
+++ src/ncu.cxx
@@ -59,6 +59,8 @@ ncu_init()
 	/* enable extra keys */
 	keypad(stdscr, true);
 
+	raw();
+
 #ifdef NCURSES_VERSION
 	/* define Alt-* keys which for some reasons aren't defined by
 	   default (tested with ncurses 6.1 on Linux) */
