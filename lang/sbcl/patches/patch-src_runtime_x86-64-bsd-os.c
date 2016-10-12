$NetBSD: patch-src_runtime_x86-64-bsd-os.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/x86-64-bsd-os.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/x86-64-bsd-os.c
@@ -1,3 +1,7 @@
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <signal.h>
 #include "sbcl.h"
 #include "runtime.h"
