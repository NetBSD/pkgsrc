$NetBSD: patch-x11_main.cpp,v 1.1 2011/11/27 19:43:33 joerg Exp $

--- x11/main.cpp.orig	2011-11-27 02:21:41.000000000 +0000
+++ x11/main.cpp
@@ -33,7 +33,7 @@ extern "C" {
 #include <X11/Xos.h>
 }
 
-#include <iostream.h>
+#include <iostream>
 
 #include "utils.h"
 #include "neth.h"
