$NetBSD: patch-pan_gui_group-prefs-dialog.cc,v 1.1 2019/08/01 22:23:14 rjs Exp $

--- pan/gui/group-prefs-dialog.cc.orig	2017-12-29 17:15:47.000000000 +0000
+++ pan/gui/group-prefs-dialog.cc
@@ -23,7 +23,7 @@ extern "C" {
   #include <glib.h>
   #include "gtk-compat.h"
 #ifdef HAVE_GTKSPELL
-  #include <enchant/enchant.h>
+  #include <enchant-2/enchant.h>
 #endif
 }
 #include <pan/general/debug.h>
