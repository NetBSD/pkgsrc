$NetBSD: patch-src-post-planar-eq.c,v 1.4 2018/11/13 11:10:41 markd Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

Disable MMX sections on SunOS.

--- src/post/planar/eq.c.orig	2018-01-11 12:49:47.000000000 +0000
+++ src/post/planar/eq.c
@@ -31,7 +31,7 @@
 #include <pthread.h>
 
 
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && !defined(__sun)
 
 #if defined(ARCH_X86_64)
 #  define MEM1(reg) "(%"reg")"
@@ -157,9 +157,11 @@ typedef struct eq_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( eq_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
             "brightness" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
             "contrast" )
 END_PARAM_DESCR( param_descr )
 
@@ -278,7 +280,7 @@ static post_plugin_t *eq_open_plugin(pos
   }
 
   process = process_C;
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && !defined(__sun)
   if( xine_mm_accel() & MM_ACCEL_X86_MMX )
     process = process_MMX;
 #endif
