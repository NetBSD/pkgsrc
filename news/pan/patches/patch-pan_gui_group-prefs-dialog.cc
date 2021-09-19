$NetBSD: patch-pan_gui_group-prefs-dialog.cc,v 1.3 2021/09/19 18:02:37 rhialto Exp $

--- pan/gui/group-prefs-dialog.cc.orig	2021-09-16 16:17:07.000000000 +0000
+++ pan/gui/group-prefs-dialog.cc
@@ -22,7 +22,7 @@
 #include <glib.h>
 #include "gtk-compat.h"
 #ifdef HAVE_GTKSPELL
-#include <enchant/enchant.h>
+#include <enchant-2/enchant.h>
 #endif
 #include <pan/general/debug.h>
 #include <pan/general/macros.h>
