$NetBSD: patch-src_ck-vt-monitor.c,v 1.1 2025/07/08 13:01:37 jperkin Exp $

GCC 14 build fixes.

--- src/ck-vt-monitor.c.orig	2025-07-08 12:55:31.442392426 +0000
+++ src/ck-vt-monitor.c
@@ -160,7 +160,7 @@ ck_vt_monitor_get_active (CkVtMonitor
 
 #if defined (__sun) && defined (HAVE_SYS_VT_H)
 static void
-handle_vt_active (void)
+handle_vt_active (int)
 {
         struct vt_stat state;
         guint          num;
