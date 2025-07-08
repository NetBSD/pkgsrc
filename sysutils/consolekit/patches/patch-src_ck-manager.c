$NetBSD: patch-src_ck-manager.c,v 1.1 2025/07/08 13:01:37 jperkin Exp $

GCC 14 build fixes.

--- src/ck-manager.c.orig	2025-07-08 12:51:28.883937548 +0000
+++ src/ck-manager.c
@@ -1362,7 +1362,7 @@ get_runtime_dir_for_user (CkManager *man
         return NULL;
 }
 
-#ifdef ENABLE_RBAC_SHUTDOWN
+#if !defined(HAVE_POLKIT) && defined(ENABLE_RBAC_SHUTDOWN)
 static gboolean
 check_rbac_permissions (CkManager             *manager,
                         GDBusMethodInvocation *context,
