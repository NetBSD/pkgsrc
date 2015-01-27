$NetBSD: patch-coda-src_kerndep_coda.h,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS defines int*_t, but not u_int*_t.
    
--- ./coda-src/kerndep/coda.h.orig	2007-08-01 18:32:36.000000000 +0000
+++ ./coda-src/kerndep/coda.h
@@ -112,11 +112,14 @@ typedef unsigned long long u_quad_t;
 #endif
 
 /* Solaris Definitions */
-#if defined(sun)
+#if defined(__sun) && defined(__SVR4)
 #include <sys/types.h>
 #include <sys/time.h>
+typedef unsigned char	    u_int8_t;
+typedef unsigned short	   u_int16_t;
+typedef unsigned int	   u_int32_t;
 typedef unsigned long long u_quad_t;
-#undef __BIT_TYPES_DEFINED__
+#define __BIT_TYPES_DEFINED__
 #endif
 
 /* Mac OS X / Darwin */
