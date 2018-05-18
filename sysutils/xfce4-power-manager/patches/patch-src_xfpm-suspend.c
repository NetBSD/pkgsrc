$NetBSD: patch-src_xfpm-suspend.c,v 1.1 2018/05/18 17:07:29 youri Exp $

Add NetBSD support.

--- src/xfpm-suspend.c.orig	2015-07-14 08:02:18.000000000 +0000
+++ src/xfpm-suspend.c
@@ -144,6 +144,9 @@ xfpm_suspend_can_suspend (void)
 #ifdef BACKEND_TYPE_OPENBSD
     return TRUE;
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+    return TRUE;
+#endif
 
     return FALSE;
 }
