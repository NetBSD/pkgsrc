$NetBSD: patch-nsswitch_winbind__nss__netbsd.c,v 1.3 2024/01/10 08:39:30 adam Exp $

Add primary group support

--- nsswitch/winbind_nss_netbsd.c.orig	2024-01-08 14:34:28.213466000 +0000
+++ nsswitch/winbind_nss_netbsd.c
@@ -176,6 +176,7 @@ netbsdwinbind_getgroupmembership(void *n
 {
 	int		*result	= va_arg(ap, int *);
 	const char 	*uname	= va_arg(ap, const char *);
+	gid_t		 agroup	= va_arg(ap, gid_t);
 	gid_t		*groups	= va_arg(ap, gid_t *);
 	int		 maxgrp	= va_arg(ap, int);
 	int		*groupc	= va_arg(ap, int *);
@@ -189,6 +190,13 @@ netbsdwinbind_getgroupmembership(void *n
 	gid_t	*wblistv;
 	int	wblistc, i, isdup, dupc;
 
+	/* add the primary group */
+	if (*groupc < maxgrp)
+		groups[*groupc] = agroup;
+	else
+		*result = -1;
+	(*groupc)++;
+
 	strncpy(request.data.username, uname,
 				sizeof(request.data.username) - 1);
 	i = winbindd_request_response(NULL, WINBINDD_GETGROUPS,
