$NetBSD: patch-nsswitch_winbind__nss__netbsd.c,v 1.2 2020/07/21 18:42:25 christos Exp $

Syntax error fix.
Add primary group support

--- nsswitch/winbind_nss_netbsd.c.orig	2020-01-31 05:25:36.000000000 -0500
+++ nsswitch/winbind_nss_netbsd.c	2020-07-21 10:24:19.651265315 -0400
@@ -176,6 +176,7 @@
 {
 	int		*result	= va_arg(ap, int *);
 	const char 	*uname	= va_arg(ap, const char *);
+	gid_t		 agroup	= va_arg(ap, gid_t);
 	gid_t		*groups	= va_arg(ap, gid_t *);
 	int		 maxgrp	= va_arg(ap, int);
 	int		*groupc	= va_arg(ap, int *);
@@ -185,10 +186,17 @@
 	};
 	struct winbindd_response response = {
 		.length = 0,
-	}
+	};
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
