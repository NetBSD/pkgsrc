$NetBSD: patch-src_window_pagerwindow.cpp,v 1.1 2020/11/18 11:39:51 nia Exp $

src/window/pagerwindow.cpp:54:4: error: 'va_list' was not declared in this scope
   54 |    va_list args;

--- src/window/pagerwindow.cpp.orig	2019-01-10 18:28:05.000000000 +0000
+++ src/window/pagerwindow.cpp
@@ -25,6 +25,7 @@
 #include "settings.hpp"
 
 #include <iostream>
+#include <stdarg.h>
 
 using namespace Ui;
 
