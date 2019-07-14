$NetBSD: patch-src_compose.c,v 1.1 2019/07/14 13:10:56 tnn Exp $

pkgsrc gtkspell uses enchant-2 now

--- src/compose.c.orig	2017-11-17 00:58:43.000000000 +0000
+++ src/compose.c
@@ -71,7 +71,7 @@
 #  include <gtk/gtkradiomenuitem.h>
 #  include <gtkspell/gtkspell.h>
 #if USE_ENCHANT
-#  include <enchant/enchant.h>
+#  include <enchant-2/enchant.h>
 #else
 #  include <aspell.h>
 #endif
