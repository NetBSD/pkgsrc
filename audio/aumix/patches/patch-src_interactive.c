$NetBSD: patch-src_interactive.c,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/interactive.c.orig	Mon Jun 26 22:51:42 2000
+++ src/interactive.c	Tue Jul 11 10:02:03 2000
@@ -1,12 +1,12 @@
 /* interactive.c:  functions used in all interactive modes */
-#include "common.h"
+#include "./common.h"
 #if defined (HAVE_CURSES) || defined (HAVE_GTK)
-#include "interactive.h"
+#include "./interactive.h"
 #ifdef HAVE_CURSES
-#include "curses.h"
+#include "./curses.h"
 #endif				/* HAVE_CURSES */
 #ifdef HAVE_GTK
-#include "gtk.h"
+#include "./gtk.h"
 #endif				/* HAVE_GTK */
 
 void            AumixSignalHandler(int signal_number)
