$NetBSD: patch-perdition_ssl.c,v 1.1 2020/03/27 20:55:58 joerg Exp $

--- perdition/ssl.c.orig	2020-03-27 14:29:57.846281348 +0000
+++ perdition/ssl.c
@@ -218,7 +218,7 @@ __perdition_verify_callback(int ok, X509
 		return 0;
 	}
 
-	if (__perdition_verify_result(ctx->error, cert) 
+	if (__perdition_verify_result(X509_STORE_CTX_get_error(ctx), cert) 
 			== X509_V_OK) {
 		return 1;
 	}
@@ -656,8 +656,8 @@ __perdition_ssl_check_common_name(X509 *
 			return -1;
 		}
 
-		if (!__perdition_ssl_compare_key(key, e->value->data,
-						 e->value->length))
+		if (!__perdition_ssl_compare_key(key, X509_NAME_ENTRY_get_data(e)->data,
+						 X509_NAME_ENTRY_get_data(e)->length))
 			return 0;
 	}
 
