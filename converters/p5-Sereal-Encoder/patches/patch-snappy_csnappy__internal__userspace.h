$NetBSD: patch-snappy_csnappy__internal__userspace.h,v 1.1 2016/12/15 01:53:34 wiedi Exp $

reorder so that __sun matches before __GNUC__

--- snappy/csnappy_internal_userspace.h.orig	2015-11-24 17:55:03.000000000 +0000
+++ snappy/csnappy_internal_userspace.h
@@ -154,11 +154,6 @@ Albert Lee
 #define __LITTLE_ENDIAN LITTLE_ENDIAN
 #define __BIG_ENDIAN BIG_ENDIAN
 
-#elif defined(__GNUC__) || defined(__ANDROID__) || defined(__CYGWIN__)
-
-#include <endian.h>
-#include <byteswap.h>
-
 #elif defined(__sun)
 
 #include <sys/byteorder.h>
@@ -173,6 +168,11 @@ Albert Lee
 #define __BYTE_ORDER __BIG_ENDIAN
 #endif
 
+#elif defined(__GNUC__) || defined(__ANDROID__) || defined(__CYGWIN__)
+
+#include <endian.h>
+#include <byteswap.h>
+
 #elif defined(__hpux)
 
 #ifdef __LP64__
