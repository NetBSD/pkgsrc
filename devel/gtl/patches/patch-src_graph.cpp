$NetBSD: patch-src_graph.cpp,v 1.1 2011/11/25 21:44:06 joerg Exp $

--- src/graph.cpp.orig	2011-11-25 18:11:10.000000000 +0000
+++ src/graph.cpp
@@ -16,6 +16,7 @@
 
 #include <cassert>
 #include <cstdio>
+#include <cstring>
 
 #include <algorithm>
 #include <queue>
