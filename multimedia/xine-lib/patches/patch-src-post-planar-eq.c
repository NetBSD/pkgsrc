$NetBSD: patch-src-post-planar-eq.c,v 1.5 2020/04/02 15:52:46 nia Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

Disable MMX sections on SunOS.

--- src/post/planar/eq.c.orig	2019-12-13 20:47:50.000000000 +0000
+++ src/post/planar/eq.c
@@ -33,7 +33,7 @@
 #include <pthread.h>
 
 
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && !defined(__sun)
 
 #if defined(ARCH_X86_64)
 #  define MEM1(reg) "(%"reg")"
@@ -155,9 +155,11 @@ typedef struct eq_parameters_s {
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
 
@@ -360,7 +362,7 @@ static post_plugin_t *eq_open_plugin(pos
   (void)audio_target;
 
   process = process_C;
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && !defined(__sun)
   if( xine_mm_accel() & MM_ACCEL_X86_MMX )
     process = process_MMX;
 #endif
