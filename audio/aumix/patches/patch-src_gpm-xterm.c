$NetBSD: patch-src_gpm-xterm.c,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/gpm-xterm.c.orig	Wed Apr 12 08:02:04 2000
+++ src/gpm-xterm.c	Tue Jul 11 10:01:31 2000
@@ -21,9 +21,9 @@
  *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  ********/
 
-#include "common.h"
+#include "./common.h"
 #if defined(HAVE_CURSES) && !defined(HAVE_LIBGPM)
-#include "gpm-xterm.h"
+#include "./gpm-xterm.h"
 
 #ifdef HAVE_USEKEYPAD
 int             gpm_keypad(WINDOW * win, int new)
