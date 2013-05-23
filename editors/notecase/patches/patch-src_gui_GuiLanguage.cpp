$NetBSD: patch-src_gui_GuiLanguage.cpp,v 1.1 2013/05/23 18:39:35 joerg Exp $

--- src/gui/GuiLanguage.cpp.orig	2013-05-23 16:49:00.000000000 +0000
+++ src/gui/GuiLanguage.cpp
@@ -13,6 +13,7 @@
 #include "../config.h"
 #include "GuiLanguage.h"
 #include <algorithm>
+#include <cstdlib>
 #include <gtk/gtk.h>
 #ifdef ENABLE_NLS
 #include <libintl.h>
