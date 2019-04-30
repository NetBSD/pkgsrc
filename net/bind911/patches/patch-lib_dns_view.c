$NetBSD: patch-lib_dns_view.c,v 1.1 2019/04/30 02:51:38 taca Exp $

* Use nta sub-directory as NetBSD base system.

--- lib/dns/view.c.orig	2019-04-06 01:47:33.000000000 +0000
+++ lib/dns/view.c
@@ -107,7 +107,7 @@ dns_view_create(isc_mem_t *mctx, dns_rda
 		goto cleanup_view;
 	}
 
-	result = isc_file_sanitize(NULL, view->name, "nta",
+	result = isc_file_sanitize("nta", view->name, "nta",
 				   buffer, sizeof(buffer));
 	if (result != ISC_R_SUCCESS)
 		goto cleanup_name;
