$NetBSD: patch-src_mouse.h,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/mouse.h.orig	Tue Apr 11 05:50:42 2000
+++ src/mouse.h	Tue Jul 11 10:02:18 2000
@@ -3,7 +3,7 @@
 #if HAVE_LIBGPM
 #include <gpm.h>
 #else
-#include "gpm-xterm.h"
+#include "./gpm-xterm.h"
 #endif				/* HAVE_LIBGPM */
 
 /* buttons for DoMouse() */
