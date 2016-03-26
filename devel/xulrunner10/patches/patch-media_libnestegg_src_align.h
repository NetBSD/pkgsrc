$NetBSD: patch-media_libnestegg_src_align.h,v 1.1 2016/03/26 23:26:14 joerg Exp $

--- media/libnestegg/src/align.h.orig	2016-03-26 12:36:49.221957164 +0000
+++ media/libnestegg/src/align.h
@@ -30,7 +30,9 @@ union max_align
 	void (*q)(void);
 };
 
+#if (__STDC_VERSION__ - 0) < 201112L && (__cplusplus - 0) < 201103L
 typedef union max_align max_align_t;
+#endif
 
 #endif
 
