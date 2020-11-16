$NetBSD: patch-ext_intl_collator_collator__sort.c,v 1.1 2020/11/16 12:10:05 ryoon Exp $

--- ext/intl/collator/collator_sort.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/collator/collator_sort.c
@@ -343,7 +343,7 @@ static void collator_sort_internal( int 
  */
 PHP_FUNCTION( collator_sort )
 {
-	collator_sort_internal( TRUE, INTERNAL_FUNCTION_PARAM_PASSTHRU );
+	collator_sort_internal( true, INTERNAL_FUNCTION_PARAM_PASSTHRU );
 }
 /* }}} */
 
@@ -535,7 +535,7 @@ PHP_FUNCTION( collator_sort_with_sort_ke
  */
 PHP_FUNCTION( collator_asort )
 {
-	collator_sort_internal( FALSE, INTERNAL_FUNCTION_PARAM_PASSTHRU );
+	collator_sort_internal( false, INTERNAL_FUNCTION_PARAM_PASSTHRU );
 }
 /* }}} */
 
