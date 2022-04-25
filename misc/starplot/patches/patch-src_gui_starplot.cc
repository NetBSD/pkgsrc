$NetBSD: patch-src_gui_starplot.cc,v 1.1 2022/04/25 14:40:13 tnn Exp $

avoid ambiguous math functions

--- src/gui/starplot.cc.orig	2008-04-10 19:18:48.000000000 +0000
+++ src/gui/starplot.cc
@@ -28,6 +28,8 @@
 #include "starplot.h"
 #include "starplot.xpm"
 
+using std::pow;
+
 #define FLIP(boolean) ((boolean) = !(boolean))
 
 // initialize globals
