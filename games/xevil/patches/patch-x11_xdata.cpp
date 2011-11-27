$NetBSD: patch-x11_xdata.cpp,v 1.1 2011/11/27 19:43:33 joerg Exp $

--- x11/xdata.cpp.orig	2011-11-27 02:24:33.000000000 +0000
+++ x11/xdata.cpp
@@ -30,7 +30,8 @@
 #include "xdata.h"
 #include "area.h"
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <X11/Xutil.h>
 #include <X11/xpm.h>
 #include <X11/Xatom.h>
