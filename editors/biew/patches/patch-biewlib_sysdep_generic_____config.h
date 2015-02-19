$NetBSD: patch-biewlib_sysdep_generic_____config.h,v 1.1 2015/02/19 22:25:54 joerg Exp $

--- biewlib/sysdep/generic/__config.h.orig	2015-02-19 20:16:55.000000000 +0000
+++ biewlib/sysdep/generic/__config.h
@@ -22,12 +22,10 @@
 #define ____CONFIG_H
 
 #include <sys/types.h>
+#include <stdint.h>
 
 #ifdef	__GLIBC__
-
 #include <endian.h>
-#include <stdint.h>
-
 #endif
 
 #define tInt8		int8_t
