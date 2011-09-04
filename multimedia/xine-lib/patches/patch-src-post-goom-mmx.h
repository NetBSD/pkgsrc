$NetBSD: patch-src-post-goom-mmx.h,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/goom/mmx.h.orig	2011-08-30 13:41:26.000000000 +0000
+++ src/post/goom/mmx.h
@@ -728,8 +728,7 @@ void zoom_filter_xmmx (int prevX, int pr
 
 #else
 
-#define	emms() __asm__ __volatile__ ("emms"::: \
-                      "st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)")
+#define	emms() __asm__ volatile ("emms" ::: "memory");
 
 #endif
 
