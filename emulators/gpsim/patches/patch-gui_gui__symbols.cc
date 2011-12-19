$NetBSD: patch-gui_gui__symbols.cc,v 1.1 2011/12/19 15:52:20 wiz Exp $

Add missing include.

--- gui/gui_symbols.cc.orig	2005-09-24 03:59:20.000000000 +0000
+++ gui/gui_symbols.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <typeinfo>
 
 #include "../config.h"
 #ifdef HAVE_GUI
