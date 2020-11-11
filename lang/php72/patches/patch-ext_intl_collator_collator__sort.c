$NetBSD: patch-ext_intl_collator_collator__sort.c,v 1.1 2020/11/11 20:01:34 markd Exp $

Use stdbool true/false macros.

--- ext/intl/collator/collator_sort.c.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/collator/collator_sort.c
@@ -346,7 +346,7 @@ static void collator_sort_internal( int
  */
 PHP_FUNCTION( collator_sort )
 {
-	collator_sort_internal( TRUE, INTERNAL_FUNCTION_PARAM_PASSTHRU );
+	collator_sort_internal( true, INTERNAL_FUNCTION_PARAM_PASSTHRU );
 }
 /* }}} */
 
@@ -540,7 +540,7 @@ PHP_FUNCTION( collator_sort_with_sort_ke
  */
 PHP_FUNCTION( collator_asort )
 {
-	collator_sort_internal( FALSE, INTERNAL_FUNCTION_PARAM_PASSTHRU );
+	collator_sort_internal( false, INTERNAL_FUNCTION_PARAM_PASSTHRU );
 }
 /* }}} */
 
