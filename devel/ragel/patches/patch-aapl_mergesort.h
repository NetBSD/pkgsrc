$NetBSD: patch-aapl_mergesort.h,v 1.1 2012/11/19 02:53:28 joerg Exp $

--- aapl/mergesort.h.orig	2012-11-19 02:09:32.000000000 +0000
+++ aapl/mergesort.h
@@ -110,7 +110,7 @@ template< class T, class Compare> void M
 		}
 		else {
 			/* Both upper and lower left. */
-			if ( compare(*lower, *upper) <= 0 )
+			if ( this->compare(*lower, *upper) <= 0 )
 				memcpy( dest++, lower++, sizeof(T) );
 			else
 				memcpy( dest++, upper++, sizeof(T) );
