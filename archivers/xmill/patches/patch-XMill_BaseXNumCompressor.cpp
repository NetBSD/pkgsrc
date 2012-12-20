$NetBSD: patch-XMill_BaseXNumCompressor.cpp,v 1.1 2012/12/20 12:39:08 ryoon Exp $

* Fix build on SmartOS

--- XMill/BaseXNumCompressor.cpp.orig	2003-01-04 23:09:36.000000000 +0000
+++ XMill/BaseXNumCompressor.cpp
@@ -76,7 +76,7 @@ void BaseXNumCompressor::Init(
 		maxdigits = 4;
 	} else {
 		/* a hack to get 1<<32 without overflow.. */
-		maxdigits = log(65536.0*65536.0) / log(base);
+		maxdigits = log(65536.0*65536.0) / log((float) base);
 	}
 }
 
@@ -258,7 +258,7 @@ void BaseXNumUncompressor::Init(
 		maxdigits = 4;
 	} else {
 		/* a hack to get 1<<32 without overflow.. */
-		maxdigits = log(65536.0*65536.0) / log(base);
+		maxdigits = log(65536.0*65536.0) / log((float) base);
 		startdiv = 1;
 		for (int i=1; i<maxdigits; i++)
 			startdiv *= base;
