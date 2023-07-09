$NetBSD: patch-output.c,v 1.1 2023/07/09 15:14:41 nia Exp $

Reduce implicit function declarations.

--- output.c.orig	1990-02-05 20:17:18.000000000 +0000
+++ output.c
@@ -12,6 +12,7 @@ static char rcsid[]= "$Header: output.c,
 #endif
 
 #include <stdio.h>
+#include <unistd.h>
 
 #ifdef M_TERMINFO
 #include <curses.h>
@@ -22,6 +23,7 @@ static char rcsid[]= "$Header: output.c,
 #ifdef XENIX
 #include <tcap.h>
 #endif
+#include <termcap.h>
 #endif
 
 #include "misc.h"
