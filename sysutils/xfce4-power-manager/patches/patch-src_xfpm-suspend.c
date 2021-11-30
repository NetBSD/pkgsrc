$NetBSD: patch-src_xfpm-suspend.c,v 1.3 2021/11/30 15:28:00 gutteridge Exp $

Add NetBSD support.

--- src/xfpm-suspend.c.orig	2020-11-04 23:23:14.000000000 +0000
+++ src/xfpm-suspend.c
@@ -152,6 +151,9 @@ xfpm_suspend_can_suspend (void)
 #ifdef BACKEND_TYPE_OPENBSD
   return TRUE;
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+  return TRUE;
+#endif
 
   return FALSE;
 }
@@ -169,6 +171,9 @@ xfpm_suspend_can_hibernate (void)
 #ifdef BACKEND_TYPE_OPENBSD
   return TRUE;
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+  return TRUE;
+#endif
 
   return FALSE;
 }
