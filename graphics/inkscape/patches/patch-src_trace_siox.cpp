$NetBSD: patch-src_trace_siox.cpp,v 1.2 2014/07/29 07:03:27 adam Exp $

Fix compilation with clang/libc++.

--- src/trace/siox.cpp.orig	2014-06-09 13:24:41.000000000 +0000
+++ src/trace/siox.cpp
@@ -9,6 +9,7 @@
 
 #include <math.h>
 #include <stdarg.h>
+#include <stdlib.h>
 #include <map>
 #include <algorithm>
 #include <cstdlib>
