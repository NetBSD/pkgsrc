$NetBSD: patch-include_common_standard.h,v 1.1 2016/02/01 10:07:56 jperkin Exp $

Fix build on SunOS.

--- include/common/standard.h.orig	2015-11-03 10:22:06.000000000 +0000
+++ include/common/standard.h
@@ -1004,7 +1004,7 @@ static inline unsigned char utf8_return_
  * the whole code is optimized out. In little endian, with a decent compiler,
  * a few bswap and 2 shifts are left, which is the minimum acceptable.
  */
-#ifndef htonll
+#if !defined(htonll) && !defined(__sun)
 static inline unsigned long long htonll(unsigned long long a)
 {
 	union {
@@ -1019,7 +1019,7 @@ static inline unsigned long long htonll(
 #endif
 
 /* Turns 64-bit value <a> from network byte order to host byte order. */
-#ifndef ntohll
+#if !defined(ntohll) && !defined(__sun)
 static inline unsigned long long ntohll(unsigned long long a)
 {
 	return htonll(a);
