$NetBSD: patch-include_atalk_acl.h,v 1.2 2016/11/07 12:46:52 christos Exp $

Provide O_IGNORE for the ones with no ACL support

--- include/atalk/acl.h.orig	2014-07-03 01:16:05.000000000 -0400
+++ include/atalk/acl.h	2016-11-06 11:20:13.660540431 -0500
@@ -61,6 +61,7 @@
 #else /* HAVE_ACLS=no */
 
 #define O_NETATALK_ACL 0
+#define O_IGNORE 0
 #define chmod_acl chmod
 
 #endif /* HAVE_ACLS */
