$NetBSD: patch-src_mouse.c,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/mouse.c.orig	Mon Jun 26 22:51:42 2000
+++ src/mouse.c	Tue Jul 11 10:02:12 2000
@@ -1,12 +1,12 @@
-#include "common.h"
+#include "./common.h"
 #if HAVE_CURSES
 #if HAVE_SYSMOUSE
 #include <machine/console.h>
 #include <errno.h>
 #endif				/* HAVE_SYSMOUSE */
-#include "interactive.h"
-#include "curses.h"
-#include "mouse.h"
+#include "./interactive.h"
+#include "./curses.h"
+#include "./mouse.h"
 #if HAVE_SYSMOUSE
 extern void     SysmouseHandler(int sig);
 extern int      Sysm_Wgetch(WINDOW * win);
