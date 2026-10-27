$NetBSD: patch-main_SAPI.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- main/SAPI.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ main/SAPI.c
@@ -185,6 +185,12 @@ SAPI_API void sapi_handle_post(void *arg
 		SG(request_info).post_entry->post_handler(SG(request_info).content_type_dup, arg TSRMLS_CC);
 		efree(SG(request_info).content_type_dup);
 		SG(request_info).content_type_dup = NULL;
+
+		/* Request parsing reached the memory limit: fail the request now that
+		 * the parsed data is consistent again */
+		if (ZEND_OOM_PENDING()) {
+			zend_handle_delayed_oom(TSRMLS_C);
+		}
 	}
 }
 
