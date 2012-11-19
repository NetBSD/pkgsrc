$NetBSD: patch-aapl_avlcommon.h,v 1.1 2012/11/19 02:53:28 joerg Exp $

--- aapl/avlcommon.h.orig	2012-11-19 02:08:19.000000000 +0000
+++ aapl/avlcommon.h
@@ -881,9 +881,9 @@ template <AVLMEL_TEMPDEF> Element *AvlTr
 		}
 
 #ifdef AVL_BASIC
-		keyRelation = compare( *element, *curEl );
+		keyRelation = this->compare( *element, *curEl );
 #else
-		keyRelation = compare( element->BASEKEY(getKey()), 
+		keyRelation = this->compare( element->BASEKEY(getKey()), 
 				curEl->BASEKEY(getKey()) );
 #endif
 
@@ -920,7 +920,7 @@ template <AVLMEL_TEMPDEF> Element *AvlTr
 	long keyRelation;
 
 	while (curEl) {
-		keyRelation = compare( *element, *curEl );
+		keyRelation = this->compare( *element, *curEl );
 
 		/* Do we go left? */
 		if ( keyRelation < 0 )
@@ -969,7 +969,7 @@ template <AVLMEL_TEMPDEF> Element *AvlTr
 			return element;
 		}
 
-		keyRelation = compare( key, curEl->BASEKEY(getKey()) );
+		keyRelation = this->compare( key, curEl->BASEKEY(getKey()) );
 
 		/* Do we go left? */
 		if ( keyRelation < 0 ) {
@@ -1023,7 +1023,7 @@ template <AVLMEL_TEMPDEF> Element *AvlTr
 			return element;
 		}
 
-		keyRelation = compare(key, curEl->getKey());
+		keyRelation = this->compare(key, curEl->getKey());
 
 		/* Do we go left? */
 		if ( keyRelation < 0 ) {
@@ -1058,7 +1058,7 @@ template <AVLMEL_TEMPDEF> Element *AvlTr
 	long keyRelation;
 
 	while (curEl) {
-		keyRelation = compare( key, curEl->BASEKEY(getKey()) );
+		keyRelation = this->compare( key, curEl->BASEKEY(getKey()) );
 
 		/* Do we go left? */
 		if ( keyRelation < 0 )
