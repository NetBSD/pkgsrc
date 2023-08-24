$NetBSD: patch-openbsd-compat_getpeereid.c,v 1.1 2023/08/24 15:26:40 vins Exp $

Silence warnings.

--- openbsd-compat/getpeereid.c.orig	2020-05-21 19:06:04.000000000 +0000
+++ openbsd-compat/getpeereid.c
@@ -48,9 +48,9 @@ getpeereid(int s, uid_t *euid, gid_t *gi
 
 	if (getpeerucred(s, &ucred) == -1)
 		return (-1);
-	if ((*euid = ucred_geteuid(ucred)) == -1)
+	if ((*euid = ucred_geteuid(ucred)) == (uid_t)-1)
 		return (-1);
-	if ((*gid = ucred_getrgid(ucred)) == -1)
+	if ((*gid = ucred_getrgid(ucred)) == (gid_t)-1)
 		return (-1);
 
 	ucred_free(ucred);
