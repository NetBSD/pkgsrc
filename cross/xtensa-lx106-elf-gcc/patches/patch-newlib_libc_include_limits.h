$NetBSD: patch-newlib_libc_include_limits.h,v 1.1 2019/09/20 15:20:20 bouyer Exp $
Don't try to use gcc's limits.h, we're not installing it.

--- newlib/libc/include/limits.h.orig	2019-09-20 12:42:00.178019535 +0200
+++ newlib/libc/include/limits.h	2019-09-20 12:42:51.347562979 +0200
@@ -16,7 +16,7 @@
 
 /* if do not have #include_next support, then we
    have to define the limits here. */
-# if !defined __GNUC__ || __GNUC__ < 2
+# if !defined __GNUC__ || __GNUC__ < 2 || 1
 
 #  ifndef _LIMITS_H
 #   define _LIMITS_H	1
@@ -126,7 +126,7 @@
 
 #endif	 /* !_LIBC_LIMITS_H_ */
 
-#if defined __GNUC__ && !defined _GCC_LIMITS_H_
+#if defined __GNUC__ && !defined _GCC_LIMITS_H_ && 0
 /* `_GCC_LIMITS_H_' is what GCC's file defines.  */
 # include_next <limits.h>
 #endif /* __GNUC__ && !_GCC_LIMITS_H_ */
