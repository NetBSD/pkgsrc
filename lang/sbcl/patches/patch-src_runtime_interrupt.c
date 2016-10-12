$NetBSD: patch-src_runtime_interrupt.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/interrupt.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/interrupt.c
@@ -40,6 +40,10 @@
  *
  * - WHN 20000728, dan 20010128 */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include "sbcl.h"
 
 #include <stdio.h>
