$NetBSD: patch-src_widgets_desktop-widget.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/widgets/desktop-widget.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/widgets/desktop-widget.cpp
@@ -78,6 +78,8 @@
 
 #include <gtk/gtk.h>
 
+using std::log;
+
 #if defined (SOLARIS) && (SOLARIS == 8)
 #include "round.h"
 using Inkscape::round;
