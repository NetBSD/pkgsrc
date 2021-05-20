$NetBSD: patch-errorwindow.c,v 1.1 2021/05/20 19:24:15 nia Exp $

Include missing header for strlen.

--- errorwindow.c.orig	2000-11-26 00:55:58.000000000 +0000
+++ errorwindow.c
@@ -12,6 +12,7 @@
 #include "buttons.h"
 #include "boxes.h"
 #include "textwindow.h"
+#include <string.h>
 #ifndef OLD_CURSES
 #include <ncurses.h>
 #else
