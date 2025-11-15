$NetBSD: patch-gcc_graphite-optimize-isl.c,v 1.1 2025/11/15 11:53:24 ryoon Exp $

--- gcc/graphite-optimize-isl.c.orig	2025-11-10 04:33:40.554381966 +0000
+++ gcc/graphite-optimize-isl.c
@@ -39,6 +39,9 @@ along with GCC; see the file COPYING3.  
 #include "dumpfile.h"
 #include "graphite.h"
 
+#include <isl/val.h>
+#include <isl/space.h>
+
 #ifdef HAVE_ISL_OPTIONS_SET_SCHEDULE_SERIALIZE_SCCS
 /* isl 0.15 or later.  */
 
