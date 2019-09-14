$NetBSD: patch-src_sendmsg-window.c,v 1.1 2019/09/14 18:57:10 nia Exp $

Support enchant2.

--- src/sendmsg-window.c.orig	2019-05-25 15:01:14.000000000 +0000
+++ src/sendmsg-window.c
@@ -68,7 +68,7 @@
 #include "geometry-manager.h"
 
 #if !HAVE_GSPELL && !HAVE_GTKSPELL_3_0_3
-#include <enchant/enchant.h>
+#include <enchant.h>
 #endif                          /* HAVE_GTKSPELL_3_0_3 */
 #if HAVE_GTKSPELL
 #include "gtkspell/gtkspell.h"
