$NetBSD: patch-src_xfpm-suspend.c,v 1.2 2021/11/30 14:52:32 gutteridge Exp $

Add NetBSD support.

--- src/xfpm-suspend.c.orig	2021-11-26 18:17:09.717521832 +0000
+++ src/xfpm-suspend.c
@@ -137,6 +137,9 @@ out:
   return ret;
 }
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+    return TRUE;
+#endif
 
 
 gboolean
