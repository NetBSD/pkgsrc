$NetBSD: patch-src_window_modewindow.cpp,v 1.1 2020/11/18 11:39:51 nia Exp $

src/window/modewindow.cpp:50:4: error: 'va_list' was not declared in this scope
   50 |    va_list args;

--- src/window/modewindow.cpp.orig	2019-01-10 18:28:05.000000000 +0000
+++ src/window/modewindow.cpp
@@ -21,6 +21,7 @@
 #include "modewindow.hpp"
 
 #include <iostream>
+#include <stdarg.h>
 
 using namespace Ui;
 
