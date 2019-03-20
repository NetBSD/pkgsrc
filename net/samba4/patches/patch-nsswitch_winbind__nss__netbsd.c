$NetBSD: patch-nsswitch_winbind__nss__netbsd.c,v 1.1 2019/03/20 19:09:10 adam Exp $

Syntax error fix.

--- nsswitch/winbind_nss_netbsd.c.orig	2019-03-20 11:23:40.911995594 +0000
+++ nsswitch/winbind_nss_netbsd.c
@@ -185,7 +185,7 @@ netbsdwinbind_getgroupmembership(void *n
 	};
 	struct winbindd_response response = {
 		.length = 0,
-	}
+	};
 	gid_t	*wblistv;
 	int	wblistc, i, isdup, dupc;
 
