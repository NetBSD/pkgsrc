$NetBSD: patch-src_runtime_bsd-os.c,v 1.3 2025/09/01 20:32:58 rjs Exp $

Add NetBSD definition for sb_GetTID function.

--- src/runtime/bsd-os.c.orig	2025-09-01 10:59:36.453394531 +0000
+++ src/runtime/bsd-os.c
@@ -64,6 +64,12 @@ int sb_GetTID()
 {
     return getthrid();
 }
+#elif defined __NetBSD__
+#include <lwp.h>
+int sb_GetTID()
+{
+    return _lwp_self();
+}
 #endif
 
 #ifdef __NetBSD__
