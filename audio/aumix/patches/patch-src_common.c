$NetBSD: patch-src_common.c,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/common.c.orig	Thu Jul  6 09:21:24 2000
+++ src/common.c	Tue Jul 11 10:01:04 2000
@@ -17,15 +17,15 @@
  * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
-#include "common.h"
+#include "./common.h"
 #ifdef HAVE_CURSES
-#include "curses.h"
-#include "gpm-xterm.h"
+#include "./curses.h"
+#include "./gpm-xterm.h"
 #endif				/* HAVE_CURSES */
 #ifdef HAVE_GTK
-#include "gtk.h"
+#include "./gtk.h"
 #endif				/* HAVE_GTK */
-#include "interactive.h"
+#include "./interactive.h"
 
 FILE           *OpenDefaultFile(char *mode);
 FILE           *setfile;
