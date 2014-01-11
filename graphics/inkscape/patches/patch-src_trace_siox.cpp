$NetBSD: patch-src_trace_siox.cpp,v 1.1 2014/01/11 17:48:52 wiz Exp $

Fix compilation with clang/libc++.

--- src/trace/siox.cpp.orig	2011-07-08 18:25:09.000000000 +0000
+++ src/trace/siox.cpp
@@ -19,6 +19,7 @@
 
 #include <math.h>
 #include <stdarg.h>
+#include <stdlib.h>
 #include <map>
 #include <algorithm>
 
