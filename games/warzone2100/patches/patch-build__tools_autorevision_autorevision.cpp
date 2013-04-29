$NetBSD: patch-build__tools_autorevision_autorevision.cpp,v 1.1 2013/04/29 21:31:11 joerg Exp $

--- build_tools/autorevision/autorevision.cpp.orig	2013-04-29 19:35:21.000000000 +0000
+++ build_tools/autorevision/autorevision.cpp
@@ -25,6 +25,7 @@
 
 #include <cstring>
 #include <cstdlib>
+#include <unistd.h>
 
 using namespace std;
 
