$NetBSD: patch-data.c,v 1.1 2012/11/01 19:39:31 joerg Exp $

--- data.c.orig	2012-10-30 20:32:41.000000000 +0000
+++ data.c
@@ -3,6 +3,8 @@
 #include <stdlib.h>
 #include <search.h>
 #include <stdlib.h>
+#include <string.h>
+#include <strings.h>
 
 #include "data.h"
 #include "log.h"
@@ -35,7 +37,7 @@ void *xmalloc(unsigned n) {
 	exit(1);
 }
 
-void *xfree(void *p) {
+void xfree(void *p) {
 
 	if (p == NULL) return;
 	vmps_log(DEBUG|SYSTEM, "FREE: %x",p);
