$NetBSD: patch-src_gpm-xterm.h,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/gpm-xterm.h.orig	Wed Apr 12 08:02:04 2000
+++ src/gpm-xterm.h	Tue Jul 11 09:54:38 2000
@@ -24,11 +24,7 @@
 #ifndef _GPM_XTERM_H_
 #define _GPM_XTERM_H_
 
-#ifdef HAVE_NCURSES_H
 #include <ncurses.h>
-#else
-#include <curses.h>
-#endif				/* HAVE_CURSES */
 
 /* Xtermish stuff */
 #define GPM_XTERM_ON \
