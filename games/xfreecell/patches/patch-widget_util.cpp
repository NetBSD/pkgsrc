$NetBSD: patch-widget_util.cpp,v 1.2 2018/02/19 09:51:48 he Exp $

--- widget/util.cpp.orig	1999-03-15 16:01:51.000000000 +0000
+++ widget/util.cpp
@@ -1,6 +1,7 @@
 #include "widget.h"
+#include <stdlib.h>
 
-unsigned long allocColor(Display* NSdpy, unsigned int red, unsigned int green, unsigned int blue)
+unsigned long allocColor(Display* NSdpy, short unsigned int red, short unsigned int green, short unsigned int blue)
 {
   XColor col = { 0, red, green, blue};
   if (XAllocColor(NSdpy, DefaultColormap(NSdpy, 0), &col) == 0) {
