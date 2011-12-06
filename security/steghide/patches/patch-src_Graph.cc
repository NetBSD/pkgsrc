$NetBSD: patch-src_Graph.cc,v 1.1 2011/12/06 19:47:32 joerg Exp $

--- src/Graph.cc.orig	2011-12-06 17:01:21.000000000 +0000
+++ src/Graph.cc
@@ -22,6 +22,7 @@
 #include <list>
 #include <map>
 #include <vector>
+#include <climits>
 
 #include "BitString.h"
 #include "CvrStgFile.h"
