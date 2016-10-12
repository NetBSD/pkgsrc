$NetBSD: patch-src_runtime_os.h,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/os.h.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/os.h
@@ -17,6 +17,10 @@
 
 #define _OS_H_INCLUDED_
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include "sbcl.h"
 #include "runtime.h"
 
