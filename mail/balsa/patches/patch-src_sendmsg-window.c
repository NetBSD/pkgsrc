$NetBSD: patch-src_sendmsg-window.c,v 1.2 2021/03/14 07:43:48 nia Exp $

Support enchant2.

--- src/sendmsg-window.c.orig	2020-12-18 20:27:46.000000000 +0000
+++ src/sendmsg-window.c
@@ -72,7 +72,7 @@
 #elif HAVE_GSPELL
 #include <gspell/gspell.h>
 #else                           /* HAVE_GTKSPELL */
-#include <enchant/enchant.h>
+#include <enchant.h>
 #include "spell-check.h"
 #endif                          /* HAVE_GTKSPELL */
 #if HAVE_GTKSOURCEVIEW
