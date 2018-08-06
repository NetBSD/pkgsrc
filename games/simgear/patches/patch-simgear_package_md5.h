$NetBSD: patch-simgear_package_md5.h,v 1.1 2018/08/06 11:03:18 jperkin Exp $

Add non-standard typedefs.

--- simgear/package/md5.h.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/package/md5.h
@@ -23,6 +23,10 @@
 typedef unsigned char    u_int8_t;
 typedef unsigned int     u_int32_t;
 typedef unsigned __int64 u_int64_t;
+#elif defined(__sun)
+typedef uint8_t		u_int8_t;
+typedef uint32_t	u_int32_t;
+typedef uint64_t	u_int64_t;
 #endif
      
 #define	MD5_BLOCK_LENGTH		64
