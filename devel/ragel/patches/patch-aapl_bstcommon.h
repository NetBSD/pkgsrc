$NetBSD: patch-aapl_bstcommon.h,v 1.2 2015/03/27 03:50:55 rodent Exp $

--- aapl/bstcommon.h.orig	2012-11-19 02:08:41.000000000 +0000
+++ aapl/bstcommon.h
@@ -361,7 +361,7 @@ template <BST_TEMPL_DEF> bool BstTable<B
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(key, GET_KEY(*mid));
+		keyRelation = this->compare(key, GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
