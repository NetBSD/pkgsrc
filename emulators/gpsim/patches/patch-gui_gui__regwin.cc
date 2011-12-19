$NetBSD: patch-gui_gui__regwin.cc,v 1.1 2011/12/19 15:52:20 wiz Exp $

Add missing include.

--- gui/gui_regwin.cc.orig	2005-10-03 13:46:22.000000000 +0000
+++ gui/gui_regwin.cc
@@ -23,6 +23,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <typeinfo>
 
 #include "../config.h"
 #ifdef HAVE_GUI
