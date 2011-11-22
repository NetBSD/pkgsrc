$NetBSD: patch-widget_scrollbar.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- widget/scrollbar.cpp.orig	2011-11-22 17:07:38.000000000 +0000
+++ widget/scrollbar.cpp
@@ -1,4 +1,5 @@
 #include "widget.h"
+#include <stdlib.h>
 
 // ## NSVScrollbar ##
 const unsigned int NSVScrollbar::_defaultWidth = 15;
