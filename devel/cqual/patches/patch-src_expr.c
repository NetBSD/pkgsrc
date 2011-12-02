$NetBSD: patch-src_expr.c,v 1.1 2011/12/02 20:50:32 marino Exp $

--- src/expr.c.orig	2003-09-10 18:52:05.000000000 +0000
+++ src/expr.c
@@ -405,8 +405,8 @@ bool check_assignment(type lhstype, type
 		{
 		  /* If this type won't generate any warnings, use it.  */
 		  if ((type_function(ttr) && type_function(ttl))
-		      ? ((!type_const(ttl) | type_const(ttr))
-			 & (!type_volatile(ttl) | type_volatile(ttr)))
+		      ? (((!type_const(ttl)) | type_const(ttr))
+			 & ((!type_volatile(ttl)) | type_volatile(ttr)))
 		      : ((type_const(ttl) | !type_const(ttr))
 			 & (type_volatile(ttl) | !type_volatile(ttr))))
 		    break;
