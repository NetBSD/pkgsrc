$NetBSD: patch-lists_include_Lists.h,v 1.1 2022/01/01 09:20:41 dholland Exp $

Avoid UB:
  - declare a suitable return type for a function returning a truth value

--- lists/include/Lists.h~	2002-03-22 22:31:52.000000000 +0000
+++ lists/include/Lists.h
@@ -84,7 +84,7 @@ extern List    LIST_Split       (List a)
 				             /* should already have second, */
 				             /* 'cos it was the passed arg) */
 
-extern List	LIST_IsWithin	(List who, List start, List end);
+extern int	LIST_IsWithin	(List who, List start, List end);
 					    /* is `who' a part of list */
 					    /* *** Deemus		*/
 
