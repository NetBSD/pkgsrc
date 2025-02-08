$NetBSD: patch-ext_intl_collator_collator__locale.c,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/collator/collator_locale.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/collator/collator_locale.c
@@ -66,7 +66,7 @@ PHP_FUNCTION( collator_get_locale )
 	COLLATOR_CHECK_STATUS( co, "Error getting locale by type" );
 
 	/* Return it. */
-	RETVAL_STRINGL( locale_name, strlen(locale_name), TRUE );
+	RETVAL_STRINGL( locale_name, strlen(locale_name), true );
 }
 /* }}} */
 
