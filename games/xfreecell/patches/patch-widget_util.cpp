$NetBSD: patch-widget_util.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- widget/util.cpp.orig	2011-11-22 17:07:23.000000000 +0000
+++ widget/util.cpp
@@ -1,4 +1,5 @@
 #include "widget.h"
+#include <stdlib.h>
 
 unsigned long allocColor(Display* NSdpy, unsigned int red, unsigned int green, unsigned int blue)
 {
