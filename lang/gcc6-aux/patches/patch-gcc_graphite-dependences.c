$NetBSD: patch-gcc_graphite-dependences.c,v 1.1 2025/11/15 11:53:24 ryoon Exp $

--- gcc/graphite-dependences.c.orig	2025-11-10 04:23:58.299357221 +0000
+++ gcc/graphite-dependences.c
@@ -39,6 +39,8 @@ along with GCC; see the file COPYING3.  
 #include "tree-data-ref.h"
 #include "graphite.h"
 
+#include <isl/space.h>
+
 /* Add the constraints from the set S to the domain of MAP.  */
 
 static isl_map *
