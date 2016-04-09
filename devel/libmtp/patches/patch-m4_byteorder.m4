$NetBSD: patch-m4_byteorder.m4,v 1.1 2016/04/09 10:09:14 richard Exp $

special case SunOS support for byteswapping

--- m4/byteorder.m4.orig	2013-03-17 08:04:49.000000000 +0000
+++ m4/byteorder.m4
@@ -106,6 +106,20 @@ dnl Linux GLIBC
 EOF],
 
    [
+dnl SunOS
+  	AC_HAVE_SYMBOL(BSWAP_32,sys/byteorder.h,
+dnl sys/byteorder.h should already be implicitly included
+  	 [cat >> "$1" << EOF
+/* Define generic byte swapping functions */
+EOF
+cat >> "$1" << EOF
+#define swap16(x) BSWAP_16(x)
+#define swap32(x) BSWAP_32(x)
+#define swap64(x) BSWAP_64(x)
+
+EOF],
+
+   [
 dnl NetBSD
   	AC_HAVE_SYMBOL(bswap32,machine/endian.h,
     dnl We're already including machine/endian.h if this test succeeds
@@ -190,6 +204,7 @@ EOF
 EOF
 	fi
 ])
+])
   	  ])
     ])
   ])
