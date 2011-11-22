$NetBSD: patch-core.h,v 1.1 2011/11/22 20:04:40 joerg Exp $

--- core.h.orig	2011-11-22 19:25:48.000000000 +0000
+++ core.h
@@ -22,6 +22,7 @@
 #include <iostream>
 #include <fstream>
 #include <string>
+#include <string.h>
 
 using namespace std;
 
