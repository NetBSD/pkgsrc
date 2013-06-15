$NetBSD: patch-jdk_src_share_native_com_sun_java_util_jar_pack_defines.h,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Avoid uLong conflicts on !BSD.

--- jdk/src/share/native/com/sun/java/util/jar/pack/defines.h.orig	2013-06-14 21:08:03.030278224 +0000
+++ jdk/src/share/native/com/sun/java/util/jar/pack/defines.h
@@ -93,7 +93,7 @@ extern int assert_failed(const char*);
 // bytes and byte arrays
 
 typedef unsigned int uint;
-#if !defined(_ALLBSD_SOURCE) || (defined(_ALLBSD_SOURCE) && defined(NO_ZLIB))
+#if defined(NO_ZLIB)
 #ifdef _LP64
 typedef unsigned int uLong; // Historical zlib, should be 32-bit.
 #else
