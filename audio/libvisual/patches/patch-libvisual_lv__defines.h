$NetBSD: patch-libvisual_lv__defines.h,v 1.1 2013/06/13 14:25:30 joerg Exp $

--- libvisual/lv_defines.h.orig	2013-06-12 21:45:45.000000000 +0000
+++ libvisual/lv_defines.h
@@ -63,13 +63,11 @@
 
 /* Compiler specific optimalization macros */
 #if __GNUC__ >= 3
-# define inline			inline __attribute__ ((always_inline))
 # define __malloc		__attribute__ ((malloc))
 # define __packed		__attribute__ ((packed))
 # define VIS_LIKELY(x)		__builtin_expect (!!(x), 1)
 # define VIS_UNLIKELY(x)	__builtin_expect (!!(x), 0)
 #else
-# define inline			/* no inline */
 # define __malloc		/* no malloc */
 # define __packed		/* no packed */
 # define VIS_LIKELY(x)		(x)
