$NetBSD: patch-widget_font.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- widget/font.cpp.orig	2011-11-22 17:07:50.000000000 +0000
+++ widget/font.cpp
@@ -1,4 +1,5 @@
 #include "widget.h"
+#include <string.h>
 
 NSFont::NSFont()
 {
