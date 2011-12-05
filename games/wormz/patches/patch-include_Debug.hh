$NetBSD: patch-include_Debug.hh,v 1.1 2011/12/05 22:47:14 joerg Exp $

--- include/Debug.hh.orig	1997-11-01 11:49:56.000000000 +0000
+++ include/Debug.hh
@@ -12,7 +12,8 @@
 #undef DEBUGPaint
 #endif
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #ifdef DEBUG
 #include <time.h>
 #endif
