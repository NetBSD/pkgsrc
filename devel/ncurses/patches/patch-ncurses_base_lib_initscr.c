$NetBSD: patch-ncurses_base_lib_initscr.c,v 1.3 2024/03/31 14:13:17 js Exp $

QNX's <sys/termio.h> complains if some of the defines from ncurses exist.

--- ncurses/base/lib_initscr.c.orig	2024-03-31 14:07:51.483557685 +0000
+++ ncurses/base/lib_initscr.c
@@ -42,7 +42,7 @@
 
 #include <curses.priv.h>
 
-#if HAVE_SYS_TERMIO_H
+#if HAVE_SYS_TERMIO_H && !defined(__QNX__)
 #include <sys/termio.h>		/* needed for ISC */
 #endif
 
