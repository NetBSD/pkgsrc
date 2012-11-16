$NetBSD: patch-src_CLucene_util_Arrays.h,v 1.1 2012/11/16 01:07:27 joerg Exp $

--- src/CLucene/util/Arrays.h.orig	2012-11-13 16:36:53.000000000 +0000
+++ src/CLucene/util/Arrays.h
@@ -151,7 +151,7 @@ CL_NS_DEF(util)
 
 			_itr1 itr1 = val1->begin();
 			_itr2 itr2 = val2->begin();
-			while ( --size >= 0 ){
+			while ( size-- > 0 ){
 				if ( !comp(*itr1,*itr2) )
 					return false;
 				itr1++;
