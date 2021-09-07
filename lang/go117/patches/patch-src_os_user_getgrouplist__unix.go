$NetBSD: patch-src_os_user_getgrouplist__unix.go,v 1.1 2021/09/07 13:31:15 jperkin Exp $

Until we switch to a native illumos bootstrap we will need to work around this
file being bootstrapped from GOHOSTOS=solaris.

--- src/os/user/getgrouplist_unix.go.orig	2021-08-16 16:29:54.000000000 +0000
+++ src/os/user/getgrouplist_unix.go
@@ -15,7 +15,11 @@ package user
 #include <grp.h>
 
 static int mygetgrouplist(const char* user, gid_t group, gid_t* groups, int* ngroups) {
+#ifdef ILLUMOS
+	return 0;
+#else
 	return getgrouplist(user, group, groups, ngroups);
+#endif
 }
 */
 import "C"
