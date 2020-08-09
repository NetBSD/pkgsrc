$NetBSD: patch-lib_dns_view.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Use nta sub-directory as NetBSD base system.

--- lib/dns/view.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/view.c
@@ -105,7 +105,7 @@ dns_view_create(isc_mem_t *mctx, dns_rda
 	isc_mem_attach(mctx, &view->mctx);
 	view->name = isc_mem_strdup(mctx, name);
 
-	result = isc_file_sanitize(NULL, view->name, "nta", buffer,
+	result = isc_file_sanitize("nta", view->name, "nta", buffer,
 				   sizeof(buffer));
 	if (result != ISC_R_SUCCESS) {
 		goto cleanup_name;
