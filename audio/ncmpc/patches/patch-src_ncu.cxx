$NetBSD: patch-src_ncu.cxx,v 1.1 2019/09/14 12:19:40 nia Exp $

(from the commit log)
date: 2010-02-25 03:08:12 +0900;  author: drochner;  state: Exp;
 Set the keyboard mode to raw() explicitely. ncurses seems to do
 this in some magical way, didn't find a hint in documentation.

--- src/ncu.cxx.orig	2019-04-10 09:08:34.000000000 +0000
+++ src/ncu.cxx
@@ -55,6 +55,8 @@ ncu_init()
 	/* enable extra keys */
 	keypad(stdscr, true);
 
+	raw();
+
 	/* initialize mouse support */
 #ifdef HAVE_GETMOUSE
 	if (options.enable_mouse)
