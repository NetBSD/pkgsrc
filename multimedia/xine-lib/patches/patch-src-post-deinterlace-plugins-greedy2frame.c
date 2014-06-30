$NetBSD: patch-src-post-deinterlace-plugins-greedy2frame.c,v 1.3 2014/06/30 13:41:00 jperkin Exp $

https://bugs.xine-project.org/show_bug.cgi?id=528

--- src/post/deinterlace/plugins/greedy2frame.c.orig	2012-05-26 21:49:59.000000000 +0100
+++ src/post/deinterlace/plugins/greedy2frame.c	2012-08-15 08:08:27.000000000 +0100
@@ -59,6 +59,8 @@
                                     int bottom_field, int second_field, int width, int height )
 
 {
+#if (!defined(__APPLE__) && defined(ARCH_X86)) || defined(ARCH_X86_64)
+
     if (xine_mm_accel() & MM_ACCEL_X86_SSE2) {
         if (((uintptr_t)output & 15) || (outstride & 15) ||
             width & 7 ||
@@ -82,6 +84,7 @@
                                        bottom_field, second_field, width, height );
         /* could fall back to 3dnow/mmx here too */
     }
+#endif /*ARCH_X86 */
 }
 
 
