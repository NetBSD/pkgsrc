$NetBSD: patch-libvisual_lv__defines.h,v 1.2 2026/01/02 12:29:21 adam Exp $

Don't redefine NULL.
No inline.

--- libvisual/lv_defines.h.orig	2023-03-20 02:04:17.000000000 +0000
+++ libvisual/lv_defines.h
@@ -38,14 +38,6 @@
 # define VISUAL_END_DECLS
 #endif /* __cplusplus */
 
-#ifdef NULL
-#undef NULL
-#endif
-
-/**
- * NULL define.
- */
-#define NULL	((void *) 0)
 
 #ifndef FALSE
 /**
@@ -68,7 +60,6 @@
 # define VIS_LIKELY(x)		__builtin_expect (!!(x), 1)
 # define VIS_UNLIKELY(x)	__builtin_expect (!!(x), 0)
 #else
-# define inline			/* no inline */
 # define __malloc		/* no malloc */
 # define __packed		/* no packed */
 # define VIS_LIKELY(x)		(x)
