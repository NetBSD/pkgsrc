$NetBSD: patch-src-post-planar-noise.c,v 1.3 2014/06/27 12:17:22 jperkin Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

Disable MMX sections on SunOS.

--- src/post/planar/noise.c.orig	2013-09-18 10:04:54.000000000 +0000
+++ src/post/planar/noise.c
@@ -155,7 +155,7 @@ static inline void lineNoise_C(uint8_t *
     }
 }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
 static inline void lineNoise_MMX(uint8_t *dst, uint8_t *src, int8_t *noise, int len, int shift){
     intarch_t mmx_len= len&(~7);
     noise+=shift;
@@ -224,7 +224,7 @@ static inline void lineNoiseAvg_C(uint8_
     }
 }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
 
 static inline void lineNoiseAvg_MMX(uint8_t *dst, uint8_t *src, int len, int8_t **shift){
     intarch_t mmx_len= len&(~7);
@@ -333,15 +333,20 @@ static const char *const enum_quality[]
  * description of params struct
  */
 START_PARAM_DESCR( noise_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to luma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to chroma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
     "Quality level of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
     "Type of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
     "Mix random noise with a (semi)regular pattern" )
 END_PARAM_DESCR( param_descr )
 
@@ -460,7 +465,7 @@ void *noise_init_plugin(xine_t *xine, vo
     class->description     = N_("Adds noise");
     class->dispose         = default_post_class_dispose;
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
     if (xine_mm_accel() & MM_ACCEL_X86_MMX) {
         lineNoise = lineNoise_MMX;
         lineNoiseAvg = lineNoiseAvg_MMX;
@@ -579,7 +584,7 @@ static int noise_draw(vo_frame_t *frame,
               frame->width * 2, frame->height, &this->params[0]);
     }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
     if (xine_mm_accel() & MM_ACCEL_X86_MMX)
         asm volatile ("emms\n\t");
     if (xine_mm_accel() & MM_ACCEL_X86_MMXEXT)
