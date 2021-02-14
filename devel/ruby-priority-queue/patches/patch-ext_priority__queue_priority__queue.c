$NetBSD: patch-ext_priority__queue_priority__queue.c,v 1.1 2021/02/14 14:58:20 taca Exp $

Do not declar/define bool, false, true if already defined.

--- ext/priority_queue/priority_queue.c.orig	2021-01-11 07:17:11.301968825 +0000
+++ ext/priority_queue/priority_queue.c
@@ -24,10 +24,16 @@
 #include "ruby.h"
 #include <math.h>
 
+#ifndef bool
 typedef _Bool bool;
+#endif
 
+#ifndef false
 #define false 0;
+#endif
+#ifndef true
 #define true 1;
+#endif
 
 // Node Structure
 typedef struct struct_priority_node {
