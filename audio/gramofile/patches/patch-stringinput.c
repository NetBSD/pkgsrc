$NetBSD: patch-stringinput.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- stringinput.c.orig	2000-03-28 21:07:26.000000000 +0000
+++ stringinput.c
@@ -8,6 +8,7 @@
  */
 
 #include "stringinput.h"
+#include <string.h>
 #ifndef OLD_CURSES
 #include <ncurses.h>
 #else
