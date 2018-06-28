$NetBSD: patch-src_ui_dialog_grid-arrange-tab.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/ui/dialog/grid-arrange-tab.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/ui/dialog/grid-arrange-tab.cpp
@@ -41,6 +41,8 @@
 //#include "sp-item-transform.h" FIXME
 #include "ui/dialog/tile.h" // for Inkscape::UI::Dialog::ArrangeDialog
 
+using std::sqrt;
+
 /*
  *    Sort items by their x co-ordinates, taking account of y (keeps rows intact)
  *
