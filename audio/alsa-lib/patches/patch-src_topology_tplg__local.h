$NetBSD: patch-src_topology_tplg__local.h,v 1.1 2016/02/18 15:15:57 wiz Exp $

--- src/topology/tplg_local.h.orig	2015-11-09 07:39:18.000000000 +0000
+++ src/topology/tplg_local.h
@@ -12,7 +12,9 @@
 
 #include <limits.h>
 #include <stdint.h>
+#ifdef __linux__
 #include <linux/types.h>
+#endif
 
 #include "local.h"
 #include "list.h"
