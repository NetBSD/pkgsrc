$NetBSD: patch-aapl_bubblesort.h,v 1.1 2012/11/19 02:53:28 joerg Exp $

--- aapl/bubblesort.h.orig	2012-11-19 02:09:50.000000000 +0000
+++ aapl/bubblesort.h
@@ -72,7 +72,7 @@ template <class T, class Compare> void B
 		changed = false;
 		for ( long i = 0; i < len-pass; i++ ) {
 			/* Do we swap pos with the next one? */
-			if ( compare( data[i], data[i+1] ) > 0 ) {
+			if ( this->compare( data[i], data[i+1] ) > 0 ) {
 				char tmp[sizeof(T)];
 
 				/* Swap the two items. */
