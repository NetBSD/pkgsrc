$NetBSD: patch-main_SAPI.c,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- main/SAPI.c.orig	2022-10-31 10:36:05.000000000 +0000
+++ main/SAPI.c
@@ -509,18 +509,23 @@ SAPI_API void sapi_deactivate(void)
 	}
 	if (SG(request_info).auth_user) {
 		efree(SG(request_info).auth_user);
+		SG(request_info).auth_user = NULL;
 	}
 	if (SG(request_info).auth_password) {
 		efree(SG(request_info).auth_password);
+		SG(request_info).auth_password = NULL;
 	}
 	if (SG(request_info).auth_digest) {
 		efree(SG(request_info).auth_digest);
+		SG(request_info).auth_digest = NULL;
 	}
 	if (SG(request_info).content_type_dup) {
 		efree(SG(request_info).content_type_dup);
+		SG(request_info).content_type_dup = NULL;
 	}
 	if (SG(request_info).current_user) {
 		efree(SG(request_info).current_user);
+		SG(request_info).current_user = NULL;
 	}
 	if (sapi_module.deactivate) {
 		sapi_module.deactivate();
