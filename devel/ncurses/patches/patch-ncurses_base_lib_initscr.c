$NetBSD: patch-ncurses_base_lib_initscr.c,v 1.1 2020/09/04 10:33:14 js Exp $

--- ncurses/base/lib_initscr.c.orig	2020-02-02 23:34:34.000000000 +0000
+++ ncurses/base/lib_initscr.c
@@ -42,7 +42,7 @@
 
 #include <curses.priv.h>
 
-#if HAVE_SYS_TERMIO_H
+#if HAVE_SYS_TERMIO_H && !defined(__QNX__)
 #include <sys/termio.h>		/* needed for ISC */
 #endif
 
