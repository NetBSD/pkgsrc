$NetBSD: patch-libmetrics__solaris__metrics.c,v 1.1 2016/02/16 12:48:18 fhajny Exp $

Portability.

--- libmetrics/solaris/metrics.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ libmetrics/solaris/metrics.c
@@ -1362,7 +1362,7 @@ part_max_used_func ( void )
 g_val_t
 cpu_steal_func ( void )
 {
-   static g_val_t val=0;
+   static g_val_t val={0};
    return val;
 }
 
