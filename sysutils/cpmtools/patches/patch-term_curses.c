$NetBSD: patch-term_curses.c,v 1.1 2023/01/15 15:41:47 thorpej Exp $

Include <stdarg.h> for needed va_list, etc. declarations.

--- term_curses.c.orig	2023-01-15 15:26:33.250094786 +0000
+++ term_curses.c	2023-01-15 15:26:49.974666733 +0000
@@ -13,6 +13,7 @@
 #include <curses.h>
 #endif
 #include <errno.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
