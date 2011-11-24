$NetBSD: patch-src_main.cpp,v 1.1 2011/11/24 14:05:09 joerg Exp $

--- src/main.cpp.orig	2011-11-24 01:03:47.000000000 +0000
+++ src/main.cpp
@@ -24,6 +24,7 @@
 #include <string>
 #include <fstream>
 #include <signal.h>
+#include <stdlib.h>
 
 
 using namespace std;
