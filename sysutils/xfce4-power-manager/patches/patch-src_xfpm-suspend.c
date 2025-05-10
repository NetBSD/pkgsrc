$NetBSD: patch-src_xfpm-suspend.c,v 1.5 2025/05/10 18:59:47 vins Exp $

Add NetBSD and SunOS support.

--- src/xfpm-suspend.c.orig	2024-11-21 06:26:21.000000000 +0000
+++ src/xfpm-suspend.c
@@ -141,7 +141,7 @@ xfpm_suspend_can_suspend (void)
 #ifdef BACKEND_TYPE_LINUX
   return linux_supports_sleep_state ("suspend");
 #endif
-#ifdef BACKEND_TYPE_OPENBSD
+#if defined (BACKEND_TYPE_OPENBSD) || defined (BACKEND_TYPE_NETBSD) || defined (BACKEND_TYPE_SOLARIS)
   return TRUE;
 #endif
 
@@ -157,7 +157,7 @@ xfpm_suspend_can_hibernate (void)
 #ifdef BACKEND_TYPE_LINUX
   return linux_supports_sleep_state ("hibernate");
 #endif
-#ifdef BACKEND_TYPE_OPENBSD
+#if defined (BACKEND_TYPE_OPENBSD) || defined (BACKEND_TYPE_NETBSD)
   return TRUE;
 #endif
 
@@ -176,6 +176,9 @@ xfpm_suspend_can_hybrid_sleep (void)
 #ifdef BACKEND_TYPE_OPENBSD
   return TRUE;
 #endif
+#if defined(BACKEND_TYPE_NETBSD) || defined(BACKEND_TYPE_SOLARIS)
+  return TRUE;
+#endif
 
   return FALSE;
 }
