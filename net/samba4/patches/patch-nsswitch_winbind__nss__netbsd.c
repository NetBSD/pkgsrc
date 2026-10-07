$NetBSD: patch-nsswitch_winbind__nss__netbsd.c,v 1.4 2026/10/07 08:53:53 wiz Exp $

Add primary group support

--- nsswitch/winbind_nss_netbsd.c.orig	2026-08-10 19:16:53.086630600 +0000
+++ nsswitch/winbind_nss_netbsd.c
@@ -176,6 +176,7 @@ netbsdwinbind_getgroupmembership(void *nsrv, void *nsc
 {
 	int		*result	= va_arg(ap, int *);
 	const char 	*uname	= va_arg(ap, const char *);
+	gid_t		 agroup	= va_arg(ap, gid_t);
 	gid_t		*groups	= va_arg(ap, gid_t *);
 	int		 maxgrp	= va_arg(ap, int);
 	int		*groupc	= va_arg(ap, int *);
@@ -188,6 +189,13 @@ netbsdwinbind_getgroupmembership(void *nsrv, void *nsc
 	};
 	gid_t	*wblistv;
 	int	wblistc, i, isdup, dupc;
+
+	/* add the primary group */
+	if (*groupc < maxgrp)
+		groups[*groupc] = agroup;
+	else
+		*result = -1;
+	(*groupc)++;
 
 	strncpy(request.data.username, uname,
 				sizeof(request.data.username) - 1);
