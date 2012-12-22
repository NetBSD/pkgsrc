$NetBSD: patch-cryptlib.h,v 1.1 2012/12/22 02:29:36 joerg Exp $

--- cryptlib.h.orig	2012-12-21 21:38:45.000000000 +0000
+++ cryptlib.h
@@ -323,7 +323,7 @@ public:
 };
 
 //! _
-extern CRYPTOPP_DLL const NullNameValuePairs g_nullNameValuePairs;
+extern CRYPTOPP_DLL NullNameValuePairs g_nullNameValuePairs;
 
 // ********************************************************
 
