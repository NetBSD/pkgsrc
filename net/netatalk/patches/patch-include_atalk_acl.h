$NetBSD: patch-include_atalk_acl.h,v 1.1 2013/07/23 13:28:17 hauke Exp $

--- include/atalk/acl.h.orig	2013-07-23 09:10:55.000000000 +0000
+++ include/atalk/acl.h
@@ -53,7 +53,7 @@ extern int remove_acl_vfs(const char *na
 
 #else /* HAVE_ACLS=no */
 
-#define O_NETATALK_ACL
+#define O_NETATALK_ACL 0
 #define chmod_acl chmod
 
 #endif /* HAVE_ACLS */
