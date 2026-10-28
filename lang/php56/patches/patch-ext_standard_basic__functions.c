$NetBSD: patch-ext_standard_basic__functions.c,v 1.3 2026/10/28 14:40:58 taca Exp $

* Work around VAX FP lack of INF

--- ext/standard/basic_functions.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/standard/basic_functions.c
@@ -3448,6 +3448,7 @@ static void basic_globals_ctor(php_basic
 	BG(user_tick_functions) = NULL;
 	BG(user_filter_map) = NULL;
 	BG(serialize_lock) = 0;
+	BG(incomplete_classes_only) = 0;
 
 	memset(&BG(serialize), 0, sizeof(BG(serialize)));
 	memset(&BG(unserialize), 0, sizeof(BG(unserialize)));
@@ -3495,7 +3496,7 @@ PHPAPI double php_get_nan(void) /* {{{ *
 
 PHPAPI double php_get_inf(void) /* {{{ */
 {
-#if HAVE_HUGE_VAL_INF
+#if defined(HAVE_HUGE_VAL_INF) || defined(__vax__)
 	return HUGE_VAL;
 #elif defined(__i386__) || defined(_X86_) || defined(ALPHA) || defined(_ALPHA) || defined(__alpha)
 	double val = 0.0;
@@ -3716,6 +3717,7 @@ PHP_RINIT_FUNCTION(basic) /* {{{ */
 	memset(BG(strtok_table), 0, 256);
 
 	BG(serialize_lock) = 0;
+	BG(incomplete_classes_only) = 0;
 	memset(&BG(serialize), 0, sizeof(BG(serialize)));
 	memset(&BG(unserialize), 0, sizeof(BG(unserialize)));
 
@@ -3814,6 +3816,22 @@ PHP_RSHUTDOWN_FUNCTION(basic) /* {{{ */
 }
 /* }}} */
 
+/* Called from php_request_startup(), before any request data is processed.
+ * The session upload progress handler (un)serializes the session and
+ * registers the session id with the URL rewriter while the request body is
+ * parsed, before RINIT. A previous request interrupted by a fatal error may
+ * have left these pointing to freed memory (CVE-2026-109619). */
+PHPAPI void php_basic_early_rinit(TSRMLS_D) /* {{{ */
+{
+	BG(serialize_lock) = 0;
+	BG(incomplete_classes_only) = 0;
+	memset(&BG(serialize), 0, sizeof(BG(serialize)));
+	memset(&BG(unserialize), 0, sizeof(BG(unserialize)));
+	/* Everything before tags is zeroed in RINIT, see url_adapt_state_ex_t */
+	memset(&BG(url_adapt_state_ex), 0, XtOffsetOf(url_adapt_state_ex_t, tags));
+}
+/* }}} */
+
 PHP_MINFO_FUNCTION(basic) /* {{{ */
 {
 	php_info_print_table_start();
