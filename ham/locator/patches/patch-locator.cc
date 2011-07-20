$NetBSD: patch-locator.cc,v 1.1 2011/07/20 12:23:01 obache Exp $

* modern C++ style

--- locator.cc.orig	2001-07-29 11:33:02.000000000 +0000
+++ locator.cc
@@ -3,10 +3,12 @@
 /* Last change 29.07.2001  */
 
 /* A few includes */
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <stdio.h>
 
+using namespace std;
+
 /* A few definitions */
 #define VERSION "0.1"
 
