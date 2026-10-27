$NetBSD: patch-ext_session_session.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- ext/session/session.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/session/session.c
@@ -2642,6 +2642,9 @@ static void php_session_rfc1867_update(p
 		progress->next_update = Z_LVAL_P(progress->post_bytes_processed) + progress->update_step;
 	}
 
+	/* Runs before RINIT: no code may run on behalf of the session data, see
+	 * BG(incomplete_classes_only) (CVE-2026-109619) */
+	BG(incomplete_classes_only)++;
 	php_session_initialize(TSRMLS_C);
 	PS(session_status) = php_session_active;
 	IF_SESSION_VARS() {
@@ -2649,16 +2652,19 @@ static void php_session_rfc1867_update(p
 		ZEND_SET_SYMBOL_WITH_LENGTH(Z_ARRVAL_P(PS(http_session_vars)), progress->key.c, progress->key.len+1, progress->data, 2, 0);
 	}
 	php_session_flush(TSRMLS_C);
+	BG(incomplete_classes_only)--;
 } /* }}} */
 
 static void php_session_rfc1867_cleanup(php_session_rfc1867_progress *progress TSRMLS_DC) /* {{{ */
 {
+	BG(incomplete_classes_only)++;
 	php_session_initialize(TSRMLS_C);
 	PS(session_status) = php_session_active;
 	IF_SESSION_VARS() {
 		zend_hash_del(Z_ARRVAL_P(PS(http_session_vars)), progress->key.c, progress->key.len+1);
 	}
 	php_session_flush(TSRMLS_C);
+	BG(incomplete_classes_only)--;
 } /* }}} */
 
 static int php_session_rfc1867_callback(unsigned int event, void *event_data, void **extra TSRMLS_DC) /* {{{ */
@@ -2678,6 +2684,11 @@ static int php_session_rfc1867_callback(
 	switch(event) {
 		case MULTIPART_EVENT_START: {
 			multipart_event_start *data = (multipart_event_start *) event_data;
+
+			/* This runs before RINIT: a previous request interrupted by a fatal
+			 * error may have left these pointing to freed memory */
+			php_rinit_session_globals(TSRMLS_C);
+
 			progress = ecalloc(1, sizeof(php_session_rfc1867_progress));
 			progress->content_length = data->content_length;
 			progress->sname_len  = strlen(PS(session_name));
@@ -2825,6 +2836,10 @@ static int php_session_rfc1867_callback(
 					php_session_rfc1867_update(progress, 1 TSRMLS_CC);
 				}
 				php_rshutdown_session_globals(TSRMLS_C);
+
+				/* $_SESSION was populated with unresolved classes, see
+				 * php_session_rfc1867_update() */
+				zend_delete_global_variable("_SESSION", sizeof("_SESSION")-1 TSRMLS_CC);
 			}
 
 			if (progress->data) {
