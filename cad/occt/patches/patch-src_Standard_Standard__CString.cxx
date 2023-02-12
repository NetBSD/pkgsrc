$NetBSD: patch-src_Standard_Standard__CString.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

paper over xlocale build error

--- src/Standard/Standard_CString.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/Standard/Standard_CString.cxx
@@ -79,7 +79,7 @@ Standard_Integer HashCodes (const Standa
     // glibc version for android platform use locale-independent implementation of
     // strtod, strtol, strtoll functions. For other system with locale-depended
     // implementations problems may appear if "C" locale is not set explicitly.
-    #if !defined(__ANDROID__) && !defined(__QNX__) && !defined(__MINGW32__)
+    #if !defined(__ANDROID__) && !defined(__QNX__) && !defined(__MINGW32__) && !defined(__NetBSD__) && !defined(__sun)
       #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #endif
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
