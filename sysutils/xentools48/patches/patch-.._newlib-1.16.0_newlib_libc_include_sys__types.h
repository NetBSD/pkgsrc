$NetBSD: patch-.._newlib-1.16.0_newlib_libc_include_sys__types.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- ../newlib-1.16.0/newlib/libc/include/sys/_types.h.orig	2017-03-28 15:10:39.000000000 +0200
+++ ../newlib-1.16.0/newlib/libc/include/sys/_types.h	2017-03-28 15:10:56.000000000 +0200
@@ -52,12 +52,8 @@
 #endif
 
 #ifndef __ssize_t_defined
-#if defined(__INT_MAX__) && __INT_MAX__ == 2147483647
-typedef int _ssize_t;
-#else
 typedef long _ssize_t;
 #endif
-#endif
 
 #define __need_wint_t
 #include <stddef.h>
