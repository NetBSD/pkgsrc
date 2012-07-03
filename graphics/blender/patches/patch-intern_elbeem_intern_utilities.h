$NetBSD: patch-intern_elbeem_intern_utilities.h,v 1.1 2012/07/03 18:10:03 joerg Exp $

--- intern/elbeem/intern/utilities.h.orig	2012-07-03 13:09:45.000000000 +0000
+++ intern/elbeem/intern/utilities.h
@@ -171,12 +171,6 @@ inline T
 MAX( T a, T b )
 { return (a < b) ? b : a ; }
 
-/* absolute value */
-template < class T >
-inline T
-ABS( T a )
-{ return (0 < a) ? a : -a ; }
-
 /* sign of the value */
 template < class T >
 inline T
