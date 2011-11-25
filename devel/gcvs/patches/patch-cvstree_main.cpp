$NetBSD: patch-cvstree_main.cpp,v 1.1 2011/11/25 21:42:44 joerg Exp $

--- cvstree/main.cpp.orig	2011-11-25 17:57:49.000000000 +0000
+++ cvstree/main.cpp
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include "getopt.h"
 #include <errno.h>
+#include <cstdlib>
 using namespace std;
 
 #if defined(_MSC_VER) && _MSC_VER < 0x514 && __GNUC__<3  // VC7  and gcc 3
