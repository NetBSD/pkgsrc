$NetBSD: patch-gcc_graphite-sese-to-poly.c,v 1.1 2025/11/15 11:53:24 ryoon Exp $

--- gcc/graphite-sese-to-poly.c.orig	2016-04-09 15:28:24.000000000 +0000
+++ gcc/graphite-sese-to-poly.c
@@ -48,6 +48,8 @@ along with GCC; see the file COPYING3.  
 #include "domwalk.h"
 #include "tree-ssa-propagate.h"
 
+#include <isl/id.h>
+#include <isl/space.h>
 #include <isl/constraint.h>
 #include <isl/set.h>
 #include <isl/map.h>
