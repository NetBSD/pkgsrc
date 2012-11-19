$NetBSD: patch-aapl_bstcommon.h,v 1.1 2012/11/19 02:53:28 joerg Exp $

--- aapl/bstcommon.h.orig	2012-11-19 02:08:41.000000000 +0000
+++ aapl/bstcommon.h
@@ -361,7 +361,7 @@ template <BST_TEMPL_DEF> bool BstTable<B
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(key, GET_KEY(*mid));
+		keyRelation = this->compare(key, GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
@@ -373,12 +373,12 @@ template <BST_TEMPL_DEF> bool BstTable<B
 
 			lower = mid - 1;
 			while ( lower != lowEnd && 
-					compare(key, GET_KEY(*lower)) == 0 )
+					this->compare(key, GET_KEY(*lower)) == 0 )
 				lower--;
 
 			upper = mid + 1;
 			while ( upper != highEnd && 
-					compare(key, GET_KEY(*upper)) == 0 )
+					this->compare(key, GET_KEY(*upper)) == 0 )
 				upper++;
 			
 			low = (Element*)lower + 1;
@@ -419,7 +419,7 @@ template <BST_TEMPL_DEF> Element *BstTab
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(key, GET_KEY(*mid));
+		keyRelation = this->compare(key, GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
@@ -457,7 +457,7 @@ template <BST_TEMPL_DEF> Element *BstTab
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(key, GET_KEY(*mid));
+		keyRelation = this->compare(key, GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
@@ -508,7 +508,7 @@ template <BST_TEMPL_DEF> Element *BstTab
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(key, GET_KEY(*mid));
+		keyRelation = this->compare(key, GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
@@ -603,7 +603,7 @@ template <BST_TEMPL_DEF> Element *BstTab
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(GET_KEY(el), GET_KEY(*mid));
+		keyRelation = this->compare(GET_KEY(el), GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
@@ -662,7 +662,7 @@ template <BST_TEMPL_DEF> Element *BstTab
 		}
 
 		mid = lower + ((upper-lower)>>1);
-		keyRelation = compare(GET_KEY(el), GET_KEY(*mid));
+		keyRelation = this->compare(GET_KEY(el), GET_KEY(*mid));
 
 		if ( keyRelation < 0 )
 			upper = mid - 1;
