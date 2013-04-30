$NetBSD: patch-dtpstree.cpp,v 1.1 2013/04/30 22:34:31 joerg Exp $

--- dtpstree.cpp.orig	2013-04-30 19:54:40.000000000 +0000
+++ dtpstree.cpp
@@ -21,6 +21,7 @@
 
 #include <cerrno>
 #include <climits>
+#include <clocale>
 #include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
