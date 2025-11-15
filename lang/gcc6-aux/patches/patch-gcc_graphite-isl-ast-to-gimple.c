$NetBSD: patch-gcc_graphite-isl-ast-to-gimple.c,v 1.1 2025/11/15 11:53:24 ryoon Exp $

--- gcc/graphite-isl-ast-to-gimple.c.orig	2016-05-31 07:27:23.000000000 +0000
+++ gcc/graphite-isl-ast-to-gimple.c
@@ -56,6 +56,10 @@ along with GCC; see the file COPYING3.  
 #include "value-prof.h"
 #include "graphite.h"
 
+#include <isl/id.h>
+#include <isl/space.h>
+#include <isl/val.h>
+
 /* We always try to use signed 128 bit types, but fall back to smaller types
    in case a platform does not provide types of these sizes. In the future we
    should use isl to derive the optimal type for each subexpression.  */
