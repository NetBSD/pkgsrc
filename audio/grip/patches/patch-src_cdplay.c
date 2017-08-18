$NetBSD: patch-src_cdplay.c,v 1.1 2017/08/18 12:21:29 triaxx Exp $

Add system dependent headers.

--- src/cdplay.c.orig	2017-07-31 21:04:11.000000000 +0000
+++ src/cdplay.c
@@ -20,6 +20,9 @@
  * USA
  */
 
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
 #include "cdplay.h"
 #include "grip.h"
 #include "config.h"
