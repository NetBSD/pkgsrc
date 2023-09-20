$NetBSD: patch-src_ChezScheme_c_expeditor.c,v 1.1 2023/09/20 22:37:40 vins Exp $

Do not require ncurses on NetBSD.

--- src/ChezScheme/c/expeditor.c.orig	2023-07-18 00:36:31.000000000 +0000
+++ src/ChezScheme/c/expeditor.c
@@ -660,9 +660,6 @@ static void s_ee_set_color(int color_id,
 # define CHTYPE int
 # include </usr/include/curses.h>
 # include </usr/include/term.h>
-#elif defined(NETBSD)
-# include <ncurses.h>
-# include <ncurses/term.h>
 #else
 # include <curses.h>
 # include <term.h>
